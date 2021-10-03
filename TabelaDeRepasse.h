#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "Roteador.h"

class Roteador; //dependencia circular

class TabelaDeRepasse {
private:
  int tamanho;

  int *enderecos;  //vetor de enderecos
  int *atrasos;    //vetor de atrasos
  Roteador **roteadoresAdj;   //vetor de reteadores adjacentes

  int posicao; //variável de controle dos vetores

  Roteador *padrao;
  int atrasoPadrao;   //atraso do roteador padrao

public:
  TabelaDeRepasse(int tamanho);
  ~TabelaDeRepasse();

  bool mapear(int endereco, Roteador* adjacente, int atraso);
  Roteador** getAdjacentes();
  int getQuantidadeDeAdjacentes();

  void setPadrao(Roteador* padrao, int atraso);

  Roteador* getProximoSalto(int endereco, int& atraso);

  void imprimir();
};

#endif // TABELADEREPASSE_H
