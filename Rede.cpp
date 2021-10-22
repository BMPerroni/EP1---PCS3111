#include <iostream>

#include "Rede.h"

Rede::Rede(int tamanho) :
tamanho(tamanho) {
  quantidade = 0;
  listaRoteadores = new Roteador*[tamanho];
}

Rede::~Rede() {
  int passador;
  passador = 0;

  while (passador < quantidade) {
    delete listaRoteadores[passador];
    passador = passador + 1;
  }

  delete[] listaRoteadores;
}

bool Rede::adicionar(Roteador *d) {
  int passador;
  passador = 0;

  if (quantidade < tamanho) {

    while (passador < quantidade) {
      if (listaRoteadores[passador]->getEndereco() == d->getEndereco()) {
        return false;
      }
      passador++;
    }

    listaRoteadores[quantidade] = d;

    quantidade++;

    return true;  
  } else {
    return false;
  }
}

Roteador *Rede::getRoteador(int endereco) {
  int passador;
  passador = 0;

  while (passador < quantidade) {
    if (listaRoteadores[passador]->getEndereco() == endereco) {
      return listaRoteadores[passador];
    }
    passador = passador + 1;
  }

  return NULL;
}

Roteador **Rede::getRoteadores() {
  return listaRoteadores;
}

int Rede::getQuantidade() {
  return quantidade;
}

void Rede::imprimir() {
  cout << "Existem" << getQuantidade() << "roteador(es)" << endl;
  if (getQuantidade() == tamanho) {
    cout << "O numero maximo de roteadores foi atingido!" << endl;
  }
}

