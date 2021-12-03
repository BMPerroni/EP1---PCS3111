#ifndef SEGMENTO_H
#define SEGMENTO_H

#include <iostream>
#include <string>

using namespace std;

class Segmento {
private:
  int PortaDeOrigem;
  int PortaDeDestino;
  string dado;
public:
  Segmento(int PortaDeOrigem, int PortaDeDestino, string dado);
  virtual ~Segmento();

  virtual int getPortaDeOrigem();
  virtual int getPortaDeDestino();
  virtual string getDado();

  virtual void imprimir();
};

#endif
