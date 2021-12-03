#include "Hospedeiro.h"

Hospedeiro::Hospedeiro (int endereco, Roteador* gateway, int atraso) : No(endereco), gateway(gateway), atraso(atraso) {
  vetorChat = new vector<Chat*>();
}


Hospedeiro::~Hospedeiro() {
  while (!vetorChat->empty()) {
    Chat *a = vetorChat->back();
    vetorChat->pop_back();
    delete a;
  }

  delete vetorChat;
}

void Hospedeiro::adicionarChat(int porta, int enderecoDestino, int portaDestino) {
  
  for (unsigned int i = 0; i < vetorChat->size(); i++) {
    if  (vetorChat->at(i)->getPorta() == porta)
      throw new logic_error ("Porta ja adicionada");
  }

  Chat* c = new Chat(this, porta, enderecoDestino, portaDestino);

  vetorChat->push_back(c);    
}

vector<Chat*>* Hospedeiro::getChats() {
  return vetorChat;
}

Chat* Hospedeiro::getChat(int porta) {
  for (unsigned int i = 0; i < vetorChat->size(); i++) {
    if  (vetorChat->at(i)->getPorta() == porta)
      return vetorChat->at(i);
  }
  return NULL;
} 

Evento* Hospedeiro::processar(int instante) {  
  if (fila->isEmpty()) {
    return NULL;
  } //fila vazia
  
  cout << "Hospedeiro " << getEndereco() << endl;
  
  Datagrama* d = fila->dequeue();

  if (d->getDestino() == getEndereco()) {
    for (unsigned int i = 0; i < vetorChat->size(); i++) {
      if (vetorChat->at(i)->getPorta() == d->getSegmento()->getPortaDeDestino()) {
        vetorChat->at(i)->receber(d);
        cout << "\t\tMensagem recebida" << endl;
        cout << vetorChat->at(i)->getTextoCompleto();
        return NULL;
      } /*else {
        cout << "\tSem chat: Origem: " << d->getOrigem() << ":" << d->getSegmento()->getPortaDeOrigem() 
        << ", Destino: " << d->getDestino() << ":" << d->getSegmento()->getPortaDeDestino() << ", " 
        << d->getSegmento()->getDado() << endl;
        delete d;
      }*/
    }
    cout << "\tSem chat: Origem: " << d->getOrigem() << ":" << d->getSegmento()->getPortaDeOrigem() 
    << ", Destino: " << d->getDestino() << ":" << d->getSegmento()->getPortaDeDestino() << ", " 
     << d->getSegmento()->getDado() << endl;
    delete d;

    return NULL;
  } else {
    Evento *e = new Evento(instante + atraso, gateway, d);
    cout << "\t\tMensagem enviada" << endl;
    return e;
  }
}

