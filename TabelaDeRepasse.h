#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "No.h"

class TabelaDeRepasse {
private:
  int tamanho;

  int *enderecos;  //vetor de enderecos
  int *atrasos;    //vetor de atrasos
  No **nosAdj;   //vetor de nos adjacentes

  int posicao; //variável de controle dos vetores

  No *padrao;
  int atrasoPadrao;   //atraso do no padrao

public:
  TabelaDeRepasse(int tamanho);
  virtual ~TabelaDeRepasse();

  virtual void mapear(int endereco, No* adjacente, int atraso);
  virtual No** getAdjacentes();
  virtual int getQuantidadeDeAdjacentes();

  virtual void setPadrao(No* padrao, int atraso);

  virtual No* getProximoSalto(int endereco, int& atraso);

  virtual void imprimir();
};

#endif // TABELADEREPASSE_H