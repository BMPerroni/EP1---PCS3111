#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

using namespace std;

class Fila {
private:
  Datagrama **fila;
  int tamanho;
  int inicio;
  int fim;
  int quantidade;
public:
  Fila(int tamanho);
  ~Fila();

  bool enqueue(Datagrama* d);
  Datagrama* dequeue();
  bool isEmpty();
  int getSize();

  void imprimir();
};

#endif