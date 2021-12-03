#ifndef REDE_H
#define REDE_H

#include "Roteador.h"
#include "No.h"
#include "Hospedeiro.h"
#include <list>

using namespace std;

class Rede {
private:
  list<No*>* listaNos;
public:
  Rede();
  virtual ~Rede();

  virtual void adicionar(No *n);
  virtual No *getNo(int endereco);
  virtual list<No*>* getNos();
  virtual list<Hospedeiro*>* getHospedeiros();

  virtual void imprimir();
  
};

#endif