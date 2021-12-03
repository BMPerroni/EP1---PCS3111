#ifndef CHAT_H
#define CHAT_H

#include "Datagrama.h"
#include "Hospedeiro.h" /*Ver se não precisa colocar todos os includes*/

using namespace std;

class Hospedeiro;

class Chat {
private:
  Hospedeiro *h;
  int porta;
  int enderecoDestino;
  int portaDestino;
  string textoCompleto;
  
public:
  Chat(Hospedeiro *h, int porta, int enderecoDestino, int portaDestino);
  virtual ~Chat();

  virtual int getPorta();
  virtual void enviar(string texto);
  virtual void receber(Datagrama* d);
  virtual string getTextoCompleto();

  virtual void imprimir();

};

#endif