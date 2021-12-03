#include <iostream>

#include "Evento.h"

Evento::Evento(int instante, No *destino, Datagrama *d) : instante(instante), destino(destino), d(d) {

}

Evento::~Evento() {
  
}

int Evento::getInstante() {
  return instante;
}

No *Evento::getDestino() {
  return destino;
}

Datagrama *Evento::getDatagrama() {
  return d;
}

void Evento::imprimir() {
  cout << "O instante corresponde a " << instante << " com datagrama " << d->getSegmento()->getDado() << " e destino " << "Pode colocar informação de no" << endl;
}

