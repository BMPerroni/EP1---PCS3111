#include <iostream>
#include <string>
/*Lembrar de adicionar todas as classes*/
#include "Agendador.h"
#include "Datagrama.h"
#include "Evento.h"
#include "Fila.h"
#include "Rede.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"

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

  Rede *redePrincipal = new Rede(6); /*Criação da Rede*/

  Agendador *agenda = new Agendador(1, redePrincipal, 10); /*Criacao do agendador*/

  Roteador *r1 = new Roteador(1); /*Criação dos Roteadores*/
  Roteador *r2 = new Roteador(2);
  Roteador *r3 = new Roteador(3);
  Roteador *r4 = new Roteador(4);
  Roteador *r5 = new Roteador(5);
  Roteador *r6 = new Roteador(6);

  r1->mapear(2, r2, 2); /*Mapeamento dos Roteadores*/
  r1->setPadrao(r3, 1);
  r2->mapear(1, r1, 2);
  r2->setPadrao(r4, 1);
  r3->mapear(1, r1, 1);
  r3->mapear(5, r5, 2);
  r3->setPadrao(r4, 1);
  r4->mapear(2, r2, 1);
  r4->mapear(6, r6, 1);
  r4->setPadrao(r3, 1);
  r5->mapear(6, r6, 2);
  r5->setPadrao(r3, 2);
  r6->mapear(5, r5, 2);
  r6->setPadrao(r4, 1);

  redePrincipal->adicionar(r1); /*Adicionando roteadores à rede*/
  redePrincipal->adicionar(r2);
  redePrincipal->adicionar(r3);
  redePrincipal->adicionar(r4);
  redePrincipal->adicionar(r5);
  redePrincipal->adicionar(r6);

  int Continuar = 1; /*Variável que controla a continuidade do programa*/

  int variavelReceptora; /*Variável para receber a opção da entrada*/

  int origem; /*Variáveis que guardam as entradas da opção 1*/
  int instante;
  int destino;
  string mensagem;

  int quantidadeTempo; /*Variável que guarda o tempo para a opção 2*/
  int passador; /*Passador para a opção 2*/

  bool verifica; /*Variável que verifica se já esetá cheio de datagramas*/

  while (Continuar == 1) {
    cout << "Simulador de Rede" << endl;
    cout << "1) Enviar um datagrama" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opcao: ";

    cin >> variavelReceptora;

    cout << endl;

    if (variavelReceptora == 1) {

      Datagrama* d;
      
      cout << "Endereco do roteador de origem: ";
      cin >> origem;

      cout << "Instante: ";
      cin >> instante;

      cout << "Endereco de destino: ";
      cin >> destino;

      cout << "Mensagem: ";
      cin >> mensagem;

      if (redePrincipal->getRoteador(origem) == NULL) {
        cout << endl << "Erro: origem desconhecida" << endl;
    }

      if (redePrincipal->getRoteador(origem) != NULL) {
      
      d = new Datagrama(origem, destino, mensagem); /*Criação do datagrama*/

      verifica = agenda->agendar(instante, redePrincipal->getRoteador(destino), d); /*Agendando o evento do datragama*/

      if (verifica == false) {
        cout << endl;
        cout << endl << "Erro: sem espaco para agendar o evento" << endl;
      }
      /*||||||||||Checar os espaços entre linhas|||||||||||*/
    }
    }

    if (variavelReceptora == 2) {
      
      passador = 0;

      cout << "Quantidade de tempo: ";
      cin >> quantidadeTempo;

      while (passador < quantidadeTempo) {
        
        cout << "Instante " << agenda->getInstante() << endl;
        cout << "---" << endl;

        agenda->processar();

        passador = passador + 1;
      }
      /*||||||||||Checar os espaços entre linhas|||||||||||*/
    }

    if (variavelReceptora == 0) {
      Continuar = 0;
    }

    cout << endl;

  }

  return 0;
}