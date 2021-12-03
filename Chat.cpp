#include <iostream>
#include <stdexcept>

#include "Segmento.h"
#include "Chat.h"

Chat::Chat(Hospedeiro *h, int porta, int enderecoDestino, int portaDestino) {
  if (h == NULL) {
    throw new invalid_argument ("Hospedeiro invalido");
  }
  else {
    this->h = h;
    this->porta = porta;
    this->enderecoDestino = enderecoDestino;
    this->portaDestino = portaDestino;
  }

  textoCompleto = "";
}

Chat::~Chat() {
}

int Chat::getPorta() {
  return porta;
}

void Chat::enviar(string texto) {
  Segmento *s = new Segmento(porta, portaDestino, texto);
  Datagrama *d = new Datagrama(h->getEndereco(), enderecoDestino, s);

  h->receber(d);

  textoCompleto = textoCompleto + "\t\t\t\tEnviado: " + texto + '\n';
}

void Chat::receber(Datagrama *d) {
  textoCompleto = textoCompleto + "\t\t\t\tRecebido: " + d->getSegmento()->getDado() + '\n';

  delete d;
}

string Chat::getTextoCompleto() {
  return textoCompleto;
}

void Chat::imprimir() {
  cout << "Chat de porta: " << porta << endl;
  cout << "Com destino: " << enderecoDestino << endl;
  cout << "E portda de destino: " << portaDestino << endl;
}
