#include "RoteadorComQoS.h"

RoteadorComQoS::RoteadorComQoS(int endereco) : Roteador(endereco, filaPrioridade = new FilaComPrioridade(TAMANHO_FILA)) {
  vetorPrioridades = new vector<int>();
}

RoteadorComQoS::~RoteadorComQoS() {
  delete vetorPrioridades;
}

void RoteadorComQoS::priorizar(int destino) {
  vetorPrioridades->push_back(destino);
}

vector<int>* RoteadorComQoS::getDestinosPriorizados() {
  return vetorPrioridades;
}

void RoteadorComQoS::receber(Datagrama *d) {
  if (filaPrioridade->getSize() > TAMANHO_FILA) {
    delete d;
    cout << " Fila em " << getEndereco() << " estourou" << endl;
  }
  int Continuar = 1;
  for (unsigned int i = 0; i < vetorPrioridades->size(); i++) {
    if  (vetorPrioridades->at(i) == d->getDestino()) {
      filaPrioridade->enqueue(d, true);
      Continuar = 0;
    }
  }
  if (Continuar == 1) {
    filaPrioridade->enqueue(d, false);
  }
}