#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H

#include "Roteador.h"
#include "Chat.h"
#include <stdexcept>
#include <vector>

class Chat;

class Hospedeiro : public No {
private:
  Roteador *gateway;
  int atraso;
  vector<Chat*>* vetorChat;
public:
  Hospedeiro(int endereco, Roteador* gateway, int atraso);
  virtual ~Hospedeiro ();

  Evento* processar(int instante);

  virtual void adicionarChat(int porta, int enderecoDestino, int portaDestino);
  virtual vector<Chat*>* getChats();
  virtual Chat* getChat(int porta);
};

#endif //HOSPEDEIRO_H