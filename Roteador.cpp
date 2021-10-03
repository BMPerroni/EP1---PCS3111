#include <iostream>
#include "Datagrama.h"
#include "Roteador.h"
#include "Evento.h"

using namespace std;

Roteador::Roteador(int endereco) {
  this->endereco = endereco;

  tabela = new TabelaDeRepasse(TAMANHO);
  fila = new Fila(TAMANHO);
}

Roteador::~Roteador() {
  delete tabela;
  delete fila;
}

bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso) {
  return tabela->mapear(endereco, adjacente, atraso);
}

void Roteador::setPadrao(Roteador* padrao, int atraso) {
  tabela->setPadrao(padrao, atraso);
}

int Roteador::getEndereco() {
  return endereco;
}

void Roteador::receber(Datagrama* d) {
  if (!fila->enqueue(d))
    cout << "   Fila em " << getEndereco() << " estourou" << endl;
}

Evento* Roteador::processar(int instante) {
  if (fila->isEmpty())  //fila vazia
    return NULL;

  cout << "Roteador " << getEndereco() << endl;   //acompanhamento - inicio

  Datagrama* d = fila->dequeue();
  if (d->getDestino() == this->endereco) {    //destino do datagrama eh o endereco do roteador

    cout << "   Recebido: " << d->getDado() << endl;  //acompanhamento

    delete d;
    return NULL;

  } else {
    int atraso;
    Roteador* r = tabela->getProximoSalto(d->getDestino(), atraso);
    if (r == NULL) {    //destino do datagrama nao esta na tabela de repasse e roteador padrao ainda eh NULL

      //acompanhamento
      cout << "   Sem proximo: Origem: " << d->getOrigem() << ", Destino: ";
      cout << d->getDestino() << ", " << d->getDado() << endl;

      delete d;
      return NULL;

    } else {
      int aux = instante + atraso;    //instante que sera de fato passado para o evento
      Evento* e = new Evento(aux, r, d);
      return e;

      // acompanhamento
      cout << "   Repassado para " << r->getEndereco() << " (instante " << aux << "): Origem: ";
      cout << d->getOrigem() << ", Destino: " << d->getDestino() << ", " << d->getDado() << endl;
    }
  }
}

void Roteador::imprimir() {
  cout << "Roteador com endereco " << getEndereco() << endl;
}