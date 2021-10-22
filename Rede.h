#ifndef REDE_H
#define REDE_H

#include "Roteador.h"

using namespace std;

class Rede {
private:
  int tamanho;
  int quantidade;
  Roteador **listaRoteadores;
public:
  Rede(int tamanho);
  ~Rede();

  bool adicionar(Roteador *r);
  Roteador *getRoteador(int endereco);
  Roteador **getRoteadores();
  int getQuantidade();

  void imprimir();
  
};

#endif