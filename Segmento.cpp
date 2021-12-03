#include <iostream>

#include "Segmento.h"

Segmento::Segmento(int PortaDeOrigem, int PortaDeDestino, string dado) :
PortaDeOrigem(PortaDeOrigem), PortaDeDestino(PortaDeDestino), dado(dado) {

}

Segmento::~Segmento() {
  
}

int Segmento::getPortaDeOrigem() {
  return PortaDeOrigem;
}

int Segmento::getPortaDeDestino() {
  return PortaDeDestino;
}

string Segmento::getDado() {
  return dado;
}

void Segmento::imprimir() {
  cout << "Segmento: " << getDado() << endl;
  cout << "Com origem: " << PortaDeOrigem << " e " << "destino: " << PortaDeDestino << endl; 
}

