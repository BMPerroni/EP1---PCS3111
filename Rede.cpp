/*#include <iostream>

#include "Rede.h"

Rede::Rede(int tamanho) :
tamanho(tamanho) {
  quantidade = 0;
  ListaRoteadores = new Roteador*[tamanho];
}

Rede::~Rede() {
  int passador;
  passador = 0;

  while (passador < quantidade) {
    delete ListaRoteadores[passador];
    passador = passador + 1;
  }

  delete[] ListaRoteadores;
}

bool Rede::adicionar(Roteador *d) {
  int passador;
  passador = 0;

  if (quantidade < tamanho) {

    while (passador < quantidade) {
      if (ListaRoteadores[passador]->getEndereco() == d->getEndereco()) {
        return false;
      }
      passador = passador + 1;
    }

    ListaRoteadores[quantidade] = d;

    quantidade = quantidade + 1;

    return true;  
  }
  
  else {
    return false;
  }
}

Roteador *Rede::getRoteador(int endereco) {
  int passador;
  passador = 0;

  while (passador < quantidade) {
    if (ListaRoteadores[passador]->getEndereco() == endereco) {
      return ListaRoteadores[passador];
    }
    passador = passador + 1;
  }

  return NULL;
}

Roteador **Rede::getRoteadores() {
  return ListaRoteadores;
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
*/
