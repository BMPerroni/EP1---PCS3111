#ifndef AGENDADOR_H
#define AGENDADOR_H

#include "Evento.h"
#include "Roteador.h"
#include "Rede.h"

using namespace std;

class Agendador {
private:
  int instanteInicial;
  Rede *rede;
  int tamanho;
  Evento **listaEventos;
  int quantidade;
  int instanteAtual;

public:
  Agendador(int instanteInicial, Rede *rede, int tamanho);
  ~Agendador();

  bool agendar(int instante, Roteador *r, Datagrama *d);
  void processar();
  int getInstante();
  
};

#endif // AGENDADOR_H