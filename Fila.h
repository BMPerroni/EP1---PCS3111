#ifndef FILA_H
#define FILA_H
#define infinito 100000000
#include "Datagrama.h"

using namespace std;

class Fila {
protected:
  Datagrama **fila;
  int tamanho;
  int inicio;
  int fim;
  int quantidade;
  int *vetorPrioridades;

public:
  Fila(int tamanho);
  virtual ~Fila();

  virtual void enqueue(Datagrama* d);
  virtual Datagrama* dequeue();
  virtual bool isEmpty();
  virtual int getSize();

  virtual void imprimir();
};

#endif