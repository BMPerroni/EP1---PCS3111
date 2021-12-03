#include <iostream>
#include <stdexcept>
#include "Fila.h"

Fila::Fila(int tamanho) :
tamanho(tamanho) {
  if (tamanho <= 0) {
    throw new invalid_argument ("Tamanho invalido");
  }
  inicio = 0;
  fim = 0;
  quantidade = 0;
  fila = new Datagrama*[tamanho];

  vetorPrioridades = new int[tamanho];

  int passador = 0;

  while (passador < tamanho) {
    vetorPrioridades[passador] = infinito;
    passador++;
  }

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

void Fila::enqueue(Datagrama *d) {
  if (quantidade != tamanho) {
    fila[fim] = d;

    if (fim == tamanho-1) {
      fim = 0;
    } else {
      fim++;
    }
    quantidade++;
  } else {
    throw new overflow_error ("A fila esta cheia");
  }
}

Datagrama *Fila::dequeue() {
  Datagrama *memoria;

  if (quantidade > 0) {
    memoria = fila[inicio];

    if (vetorPrioridades[inicio] != infinito) {
        vetorPrioridades[inicio] = infinito;
    }

    if (inicio == tamanho-1) {
      inicio = 0;
    } else {
      inicio++;
    }

    quantidade--;


    return memoria;

  } else {
    throw new underflow_error ("A fila esta vazia");
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