#include <iostream>

#include "Evento.h"

Evento::Evento(int instante, Roteador *destino, Datagrama *d) :
instante(instante), destino(destino), d(d) {

}

Evento::~Evento() {
  
}

int Evento::getInstante() {
  return instante;
}

Roteador *Evento::getDestino() {
  return destino;
}

Datagrama *Evento::getDatagrama() {
  return d;
}

void Evento::imprimir() {
  cout << "O instante corresponde a " << instante << endl;
}

