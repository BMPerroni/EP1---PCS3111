#include <iostream>
#include <stdexcept>
#include "Rede.h"

Rede::Rede() {
  listaNos = new list<No*>();
}

Rede::~Rede() {
  while (!listaNos->empty()) {
    No *a = listaNos->back();
    listaNos->pop_back();
    delete a;
  }

  delete listaNos;
}

void Rede::adicionar(No *n) {
  list<No*>::iterator i = listaNos->begin();

  while (i != listaNos->end()) {
    if ((*i)->getEndereco() == n->getEndereco()) {
      throw new logic_error("No ja adicionado!");
    }
    i++;
   }

  listaNos->push_back(n);

}

No * Rede::getNo(int endereco) {
  list<No*>::iterator i = listaNos->begin();

  while (i != listaNos->end()) {
    if ((*i)->getEndereco() == endereco) {
      return (*i);
    }
    i++;
   }

   return NULL;
}

list<Hospedeiro*>* Rede::getHospedeiros() {
  list <Hospedeiro*>* listaHospedeiros = new list<Hospedeiro*>();

  list<No*>::iterator i = listaNos->begin();

  while (i != listaNos->end()) {
    Hospedeiro *h = dynamic_cast<Hospedeiro*>(*i);
    if (h != NULL) {
      listaHospedeiros->push_back(h);
    }
    i++;
   }

   return listaHospedeiros;
}

list<No*>* Rede::getNos() {
  return listaNos;
}


void Rede::imprimir() {
  cout << "Rede com: " << listaNos->size() << "nos e " << getHospedeiros()->size() << "hospedeiros";  
}

