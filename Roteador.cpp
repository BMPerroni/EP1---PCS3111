#include <iostream>
#include "Roteador.h"

using namespace std;

Roteador::Roteador(int endereco) : No(endereco) {
  tabela = new TabelaDeRepasse(TAMANHO_TABELA);
}

Roteador::Roteador(int endereco, Fila* fila) : No(endereco, fila) {
  tabela = new TabelaDeRepasse(TAMANHO_TABELA);
}

Roteador::~Roteador() {
  delete tabela;
}

void Roteador::mapear(int endereco, No* adjacente, int atraso) {
  return tabela->mapear(endereco, adjacente, atraso);
}

void Roteador::setPadrao(Roteador* padrao, int atraso) {
  tabela->setPadrao(padrao, atraso);
}

Evento* Roteador::processar(int instante) {
  if (fila->isEmpty()) {
    return NULL;
  } //fila vazia
  cout << "Roteador " << getEndereco() << endl;   //acompanhamento - inicio

  Datagrama* d = fila->dequeue();
  if (d->getDestino() == this->endereco) {   //destino do datagrama eh o endereco do roteador 

    cout << "   Recebido: " << d->getSegmento()->getDado() << endl;  //acompanhamento

    delete d;
    return NULL;

  } else {
    int atraso;
    No* r = tabela->getProximoSalto(d->getDestino(), atraso);
    if (r == NULL) {    //destino do datagrama nao esta na tabela de repasse e roteador padrao ainda eh NULL

      //acompanhamento
      cout << "   Sem proximo: Origem: " << d->getOrigem() << ":" << d->getSegmento()->getPortaDeOrigem() 
      << ", Destino: " << d->getDestino() << ":" << d->getSegmento()->getPortaDeDestino() << ", " 
      << d->getSegmento()->getDado() << endl;

      delete d;
      return NULL;

    } else { 
      int aux = instante + atraso;    //instante que sera de fato passado para o evento
      Evento* e = new Evento(aux, r, d);

      // acompanhamento
      cout << "   \t\tRepassado para " << r->getEndereco() << " (instante " << aux << "): Origem: ";
      cout << d->getOrigem() << ":" << d->getSegmento()->getPortaDeOrigem() << ", Destino: " << d->getDestino() << ":" << d->getSegmento()->getPortaDeDestino() << ", " << d->getSegmento()->getDado() << endl;
      return e;
    }
  }
}
