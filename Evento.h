/*#ifndef EVENTO_H
#define EVENTO_H

#include "Datagrama.h"
#include "Roteador.h"

using namespace std;

class Roteador; /*Dependência circular*/
/*
class Evento {
private:
    int instante;
    Roteador* destino;
    Datagrama* d;
public:
    Evento(int instante, Roteador *destino, Datagrama *d);
    ~Evento();

    int getInstante();
    Roteador* getDestino();
    Datagrama* getDatagrama();

    void imprimir();
};

#endif
*/