#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H

#include "Rede.h"

using namespace std;

class PersistenciaDeRede {
private:
  string arquivo;
  Rede *rede;
public:
  PersistenciaDeRede(string arquivo);
  virtual ~PersistenciaDeRede();

  virtual Rede* carregar();
};

#endif