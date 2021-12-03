#include <iostream>
#include "No.h"

No::No(int endereco) : endereco(endereco) {
  fila = new Fila(TAMANHO_FILA);
}

No::No(int endereco, Fila* fila) : endereco(endereco), fila(fila) {
}

No::~No() {
  delete fila;
}

int No::getEndereco() {
  return endereco;
}

void No::receber(Datagrama *d) {
  if (fila->getSize() == TAMANHO_FILA) {
    delete d;
    cout << " Fila em " << getEndereco() << " estourou" << endl;
  }
  fila->enqueue(d);
}

void No::imprimir() {
  cout << "No com endereco " << getEndereco() << endl;
  cout << "Fila de: " << fila->getSize() << endl;
}