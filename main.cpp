#include <iostream>
#include <string>

#include "Datagrama.h"
#include "Fila.h"

using namespace std;

void Teste() { /*Acho que dá pra ir testando as coisas por aqui*/
  Datagrama *d = new Datagrama(2, 4, "1");
  d->imprimir();

  Fila *f = new Fila(3);
  f->imprimir();
  Datagrama *e = new Datagrama(2, 4, "2");
  Datagrama *g = new Datagrama(2, 4, "3");
  f->enqueue(d);
  f->enqueue(e);
  f->enqueue(g);
  f->imprimir();
  Datagrama *over = new Datagrama(2, 4, "overflow");
  f->enqueue(over);
  f->imprimir();
  f->dequeue();
  f->imprimir();
  f->enqueue(over);
  f->imprimir();
  delete f;

}

int main() {
  Teste();
  return 0;
}