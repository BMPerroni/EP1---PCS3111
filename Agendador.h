#ifndef AGENDADOR_H
#define AGENDADOR_H

#include "Evento.h"
#include "Roteador.h"
#include "Rede.h"

using namespace std;

class Agendador {
private:
  Rede *rede;
  int tamanho;
  Evento **listaEventos;
  int quantidade;
  int instanteAtual;
  int instanteInicial;
  int fim;
  int inicio;
  bool isEmpty();
  bool enqueue(Evento *e);
  Evento *dequeue();
  
public:
  Agendador(int instanteInicial, Rede *rede, int tamanho);
  virtual~Agendador();

  virtual bool agendar(int instante, No *n, Datagrama *d);
  virtual void processar();
  virtual int getInstante();
};

#endif // AGENDADOR_H