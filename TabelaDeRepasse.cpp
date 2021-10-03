#include <iostream>

#include "TabelaDeRepasse.h"
#include "Roteador.h"

using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho) {
  this->tamanho = tamanho;

  padrao = NULL;
  atrasoPadrao = 0;

  posicao = 0;

  enderecos = new int [tamanho];
  atrasos = new int [tamanho];
  roteadoresAdj = new Roteador* [tamanho];
}

TabelaDeRepasse::~TabelaDeRepasse() {
  delete[] enderecos;
  delete[] atrasos;
  delete[] roteadoresAdj;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente, int atraso) {
  if (posicao == tamanho) //vetores cheios
    return false;

  for (int i = 0; i < posicao; i++) {
      if (enderecos[i] == endereco)   //endereco já está na tabela
        return false;
  }

  enderecos[posicao] = endereco;
  atrasos[posicao] = atraso;
  roteadoresAdj[posicao] = adjacente;

  posicao++;

  return true;
}

Roteador** TabelaDeRepasse::getAdjacentes() {
  return roteadoresAdj;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
  return posicao;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao, int atraso) {
  this->padrao = padrao;
  atrasoPadrao = atraso;
}

Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso) {
  for (int i = 0; i < posicao; i++) {
    if (enderecos[i] == endereco){
      atraso = atrasos[i];
      return roteadoresAdj[i];
    }
  }

  atraso = atrasoPadrao;
  return padrao;
}

void TabelaDeRepasse::imprimir() {
  cout << "Tabela de repasse com tamanho " << tamanho << " possui: " << endl;
  for (int i = 0; i < posicao; i++) {
    cout << "Roteador " << roteadoresAdj[i] << " - Endereco " << enderecos[i] << " - Atraso " << atrasos[i] << endl;
  }
}
