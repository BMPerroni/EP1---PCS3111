#include <iostream>
#include "Fila.h"

Fila::Fila(int tamanho) :
tamanho(tamanho) {
  inicio = 0;
  fim = 0;
  quantidade = 0; 

  fila = new Datagrama*[tamanho]; 
}

Fila::~Fila() {
  int passador;
  passador = 0;

  while (passador < quantidade) {
    delete fila[passador];
    passador = passador + 1;
  }

  delete[] fila;
}

bool Fila::enqueue(Datagrama *d) {
  if (quantidade != tamanho) {
    fila[fim] = d;

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

Datagrama *Fila::dequeue() {
  Datagrama *memoria;

  if (quantidade > 0) {
    memoria = fila[inicio];

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

bool Fila::isEmpty() {
  if (quantidade == 0) {
    return true;
  } else {
    return false;
  }
}

int Fila::getSize() {
  return quantidade;
}

void Fila::imprimir() {
  cout << "Ha " << getSize() << " datagrama(s) na fila!" << endl;
  if (isEmpty() == true) {
    cout << "A fila esta vazia!" << endl;
  }
  
}
