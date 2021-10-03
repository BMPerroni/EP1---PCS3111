#include <iostream>

#include "Agendador.h"

Agendador::Agendador (int instanteInicial, Rede *rede, int tamanho) :  instanteInicial(instanteInicial), rede(rede), tamanho(tamanho) {
  listaEventos = new Evento*[tamanho];

  for (int i=0; i<tamanho; i++) {
    listaEventos[i] = NULL;
  }
  
  quantidade = 0;
  instanteAtual = instanteInicial;
}


Agendador::~Agendador() {
  
}

bool Agendador::agendar(int instante, Roteador *r, Datagrama *d) {
  Evento *e = new Evento(instante, r, d);
  if (quantidade == tamanho) 
    return false;
  
  for (int i = 0; i < quantidade; i++) {
    if (listaEventos[i] == NULL) {
      listaEventos[i] = e;
      quantidade++;
    }  
  }      
  return true;  
}

void Agendador::processar() {
  int passador = 0;

  while (passador < quantidade) {
    if (listaEventos[passador]->getInstante() == instanteAtual) {
      listaEventos[passador]->getDestino()->receber(listaEventos[passador]->getDatagrama());

      delete listaEventos[passador];
      
      listaEventos[passador] = NULL;
      quantidade = quantidade - 1;
    }
    passador = passador + 1;
  }
  passador = 0;

  Evento *e;

  while (passador < rede->getQuantidade()) {
    e = rede->getRoteadores()[passador]->processar(instanteAtual);
    agendar(e->getInstante(), e->getDestino(), e->getDatagrama());
    passador = passador + 1;
    
  }

  instanteAtual = instanteAtual + 1;
}

int Agendador::getInstante() {
  return instanteAtual;
}
