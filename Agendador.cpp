#include <iostream>

#include "Agendador.h"

Agendador::Agendador (int instanteInicial, Rede *rede, int tamanho) :  instanteInicial(instanteInicial), rede(rede), tamanho(tamanho) {
  listaEventos = new Evento*[tamanho];
  
  quantidade = 0;
  inicio = 0;
  fim = 0;
  instanteAtual = instanteInicial;
}


Agendador::~Agendador() {
  for (int i = 0; i < tamanho; i++) {
    if (listaEventos[i] != NULL)
      delete listaEventos[i];
  }
  
  delete [] listaEventos;
}

bool Agendador::agendar(int instante, Roteador *r, Datagrama *d) {
  Evento *e = new Evento(instante, r, d);
  bool teste = enqueue(e);

  return teste;
}

void Agendador::processar() {
  
  Evento *a;
  int quantidadeFixa = quantidade;
  if (quantidadeFixa > 0) {
    for (int i=0; i < quantidadeFixa; i++){
      a = dequeue(); 
      if (a->getInstante() == getInstante()) {
        a->getDestino()->receber(a->getDatagrama());
        delete a;
      } else {
        enqueue(a);
      }
    }
  }

  
  int passador;
  passador = 0;    
  Evento *e;
  
  while (passador < rede->getQuantidade()) {
    e = rede->getRoteadores()[passador]->processar(instanteAtual);
    
    if (e != NULL) {
      agendar(e->getInstante(), e->getDestino(), e->getDatagrama());
    }
    passador++;
  }
  instanteAtual++;
}

int Agendador::getInstante() {
  return instanteAtual;
}

bool Agendador::enqueue(Evento *e) {
  if (quantidade != tamanho) {
    listaEventos[fim] = e;

    if (fim == tamanho-1) {
      fim = 0;
    } else {
      fim++;
    }
    
    quantidade++;
    
    return true;
  } else {
    return false;
  }
}

Evento *Agendador::dequeue() {
  Evento *memoria;

  if (quantidade > 0) {
    memoria = listaEventos[inicio];

    if (inicio == tamanho-1) {
      inicio = 0;
    } else {
      inicio++;
    }
    quantidade--;

    return memoria;
  } else {
    return NULL;
  }
}