#include <iostream>
#include <stdexcept>

#include "TabelaDeRepasse.h"

using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho) : tamanho(tamanho) {
  if(tamanho <= 0) 
    throw new invalid_argument ("Tamanho invalido");
  
  padrao = NULL;
  atrasoPadrao = 0;

  posicao = 0;

  enderecos = new int [tamanho];
  atrasos = new int [tamanho];
  nosAdj = new No* [tamanho];
}

TabelaDeRepasse::~TabelaDeRepasse() {
  delete[] enderecos;
  delete[] atrasos;
  delete[] nosAdj;
}

void TabelaDeRepasse::mapear(int endereco, No* adjacente, int atraso) {
  if (posicao == tamanho) //vetores cheios
    throw new overflow_error ("nosAdj estourou");

  for (int i = 0; i < posicao; i++) {
    if (enderecos[i] == endereco)   //endereco já está na tabela
      throw new invalid_argument ("Endereco ja adicionado");
  }

  enderecos[posicao] = endereco;
  atrasos[posicao] = atraso;
  nosAdj[posicao] = adjacente;

  posicao++;
}

No** TabelaDeRepasse::getAdjacentes() {
  return nosAdj;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
  return posicao;
}

void TabelaDeRepasse::setPadrao(No* padrao, int atraso) {
  this->padrao = padrao;
  atrasoPadrao = atraso;
}

No* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso) {
  for (int i = 0; i < posicao; i++) {
    if (enderecos[i] == endereco){
      atraso = atrasos[i];
      return nosAdj[i];
    }
  }

  atraso = atrasoPadrao;
  return padrao;
}

void TabelaDeRepasse::imprimir() {
  cout << "Tabela de repasse com tamanho " << tamanho << " possui: " << endl;
  for (int i = 0; i < posicao; i++) {
    cout << "No " << nosAdj[i] << " - Endereco " << enderecos[i] << " - Atraso " << atrasos[i] << endl;
  }
}
