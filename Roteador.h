#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "TabelaDeRepasse.h"
#include "Fila.h"
#include "No.h"

class Roteador : public No {
private:
  TabelaDeRepasse *tabela;

protected:
  Roteador(int endereco, Fila* fila);

public:
  Roteador(int endereco);
  virtual ~Roteador();

  virtual void mapear(int endereco, No* adjacente, int atraso);
  virtual void setPadrao(Roteador* padrao, int atraso);

  Evento* processar(int instante);

  static const int TAMANHO_TABELA = 10;
};

#endif // ROTEADOR_H
