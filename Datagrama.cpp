#include <iostream>
#include <string>
#include "Datagrama.h"

using namespace std;

Datagrama::Datagrama(int origem, int destino, string dado) {
  this->origem = origem;
  this->destino = destino;
  this->dado = dado;
}

Datagrama::~Datagrama() {
  cout << "Datagrama destruido" << endl;
}

int Datagrama::getOrigem() {
  return origem;
}

int Datagrama::getDestino() {
  return destino;
}

string Datagrama::getDado() {
  return dado;
}

void Datagrama::imprimir() {
  cout << "Datagrama com origem " << getOrigem() << " e destino " << getDestino() << " contendo " << getDado() << endl;
}
