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
  
  return enqueue(e);
}

void Agendador::processar() {
  
  Evento *a;
  for (int i=0; i < tamanho; i++){
    a = dequeue();
    if (a != NULL) {
      if (a->getInstante() == instanteAtual) {
        a->getDestino()->receber(a->getDatagrama()); 
        delete a;
      } else {
        enqueue(a);
      }
    } else {
      enqueue(a);
      if (inicio == fim && listaEventos[0] == NULL) {
        quantidade = 0;
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
      fim = fim + 1;
    }
    
    quantidade = quantidade + 1;
    
    return true;
  } else {
    return false;
  }
}

Evento *Agendador::dequeue() {
  Evento *memoria;

  if (quantidade >0) {
    memoria = listaEventos[inicio];

    if (inicio == tamanho) {
      inicio = 0;
    } else {
      inicio = inicio + 1;
    }
    quantidade = quantidade - 1;

    return memoria;
  } else {
    return NULL;
  }
}