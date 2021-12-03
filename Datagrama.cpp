#include <iostream>
#include <string>
#include "Datagrama.h"

using namespace std;

Datagrama::Datagrama(int origem, int destino, Segmento* dado) {
  this->origem = origem;
  this->destino = destino;
  this->dado = dado;
}

Datagrama::~Datagrama() {
  delete dado;
}

int Datagrama::getOrigem() {
  return origem;
}

int Datagrama::getDestino() {
  return destino;
}

Segmento* Datagrama::getSegmento() {
  return dado;
}

void Datagrama::imprimir() {
  cout << "Datagrama com origem " << getOrigem() << " e destino " << getDestino() << " contendo " << getSegmento() << endl;
}
