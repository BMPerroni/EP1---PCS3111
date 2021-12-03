#ifndef FILACOMPRIORIDADE_H
#define FILACOMPRIORIDADE_H

#include "Fila.h"

using namespace std;

class FilaComPrioridade : public Fila {
public:
  FilaComPrioridade(int tamanho);
  virtual ~FilaComPrioridade();

  virtual void enqueue(Datagrama* d, bool prioritario);

  using Fila::enqueue;
private:
    int somaPrioridades;
};

#endif
