#include <iostream>

#include "Agendador.h"

Agendador::Agendador (int instanteInicial, Rede *rede, int tamanho) :  instanteInicial(instanteInicial), rede(rede), tamanho(tamanho) {
  listaEventos = new Evento*[tamanho];

  for (int i=0; i<tamanho; i++) {
    listaEventos[i] = NULL;
  }
  
  quantidade = 0;
  inicio = 0;
  fim =0;
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
  bool retornar;
  int passador;

  /*if (quantidade == tamanho) {
    return false;
  }

  else {
    passador = 0;
    Evento *e = new Evento(instante, r, d);
    while (passador < tamanho) {
      if (listaEventos[passador] == NULL) {
        listaEventos[passador] = e;
        quantidade = quantidade + 1;
        break;
      }
      passador = passador +1;
    }
  }
  return true;*/
  Evento *e = new Evento(instante, r, d);
  retornar = enqueue(e);
  return retornar;
}

void Agendador::processar() {
  
  /*int passador = 0;
    int contador;
  while (passador < tamanho) {
    if (listaEventos[passador] != NULL && listaEventos[passador]->getInstante() == instanteAtual) {
      
      listaEventos[passador]->getDestino()->receber(listaEventos[passador]->getDatagrama());

      delete listaEventos[passador];

      quantidade = quantidade - 1; 

      if (passador == 0) {
        contador = 0;
        while (contador < quantidade) {
          listaEventos[contador] = listaEventos[contador+1]
          
        }
        listaEventos[contador] = NULL;
      }

      listaEventos[passador] = NULL;
          
         
    }
    passador = passador + 1;
  } */ 
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
    passador = passador + 1;
  }
  instanteAtual = instanteAtual + 1;
}

int Agendador::getInstante() {
  return instanteAtual;
}

bool Agendador::enqueue(Evento *e) {
  if (quantidade != tamanho) {
    listaEventos[fim] = e;

    if (fim == tamanho-1) {
      fim = 0;
    }

    else {
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
