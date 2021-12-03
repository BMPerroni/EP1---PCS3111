#ifndef ROTEADORCOMQOS_H
#define ROTEADORCOMQOS_H

#include <vector>
#include "Roteador.h"
#include "FilaComPrioridade.h"

class RoteadorComQoS : public Roteador {
private:
  FilaComPrioridade *filaPrioridade;
  vector<int>* vetorPrioridades;

public:
  RoteadorComQoS(int endereco);
  virtual ~RoteadorComQoS();

  void receber(Datagrama* d);
  virtual void priorizar(int destino);
  virtual vector<int>* getDestinosPriorizados();
};

#endif // ROTEADORCOMQOS_H
