#include <string>

#include "Agendador.h"
#include "Evento.h"
#include "Fila.h"
#include "Rede.h"
#include "RoteadorComQoS.h"
#include "TabelaDeRepasse.h"
#include "PersistenciaDeRede.h"

using namespace std;

int main() {
  try {
    string arquivo;
    int instanteInicial;
    Rede *redePrincipal;

    cout << "Nome do arquivo: ";
    cin >> arquivo;
    cout << endl;
    cout << "Instante inicial: ";
    cin >> instanteInicial;
    cout << endl;

    PersistenciaDeRede* PR = new PersistenciaDeRede(arquivo);
    redePrincipal = PR->carregar(); /*Criação da Rede*/

    Agendador *agenda = new Agendador(instanteInicial, redePrincipal, 10); /*Criacao do agendador*/

    int Continuar = 1; /*Variável que controla a continuidade da interface*/

    int variavelReceptora; /*Variável para receber a opção da entrada*/
    int instante = 1;
    /*Criação da interface*/
    while (Continuar == 1) {
      cout << "Simulador de Rede" << endl;
      cout << "1) Enviar um datagrama" << endl;
      cout << "2) Passar tempo" << endl;
      cout << "0) Sair" << endl;
      cout << "Escolha uma opcao: ";

      cin >> variavelReceptora;

      cout << endl;

      if (variavelReceptora == 1) {
        int enderecoHospedeiro;
        int portaChat;
        string mensagem;

        list<Hospedeiro*>* listaHospedeiros = redePrincipal->getHospedeiros();

        list<Hospedeiro*>::iterator i = listaHospedeiros->begin();

        while (i != listaHospedeiros->end()) {
          cout << "Hospedeiro: " << (*i)->getEndereco() << endl;
          vector<Chat*>* vetorChats = (*i)->getChats();
          
          for (unsigned int j = 0; j < vetorChats->size(); j++) {
            cout << "\t\tChat: " << vetorChats->at(j)->getPorta() << endl; 
          }
          i++;
        }

        cout << "Endereco do hospedeiro: ";
        cin >> enderecoHospedeiro;

        
        cout << "Porta do chat: ";
        cin >> portaChat;
        
        cout << "Conteudo: " << endl;

        No* no;

        no = redePrincipal->getNo(enderecoHospedeiro);

        Hospedeiro *hospedeiro = dynamic_cast<Hospedeiro*>(no);
        
        if (hospedeiro->getChat(portaChat) == NULL) {
          cout << "Erro: origem desconhecida" << endl;
        } else {
          cout << hospedeiro->getChat(portaChat)->getTextoCompleto() << endl;
        }

        cout << "Mensagem: ";
        cin >> mensagem;

        hospedeiro->getChat(portaChat)->enviar(mensagem);
      }

      if (variavelReceptora == 2) {
        int quantidadeTempo;

        cout << "Quantidade de tempo: ";
        cin >> quantidadeTempo;
        cout << endl;

        for (int i = 1; i <= quantidadeTempo; i++) {
          cout << '\n';
          cout << "Instante " << instante << endl;
          cout << "---" << endl;
          agenda->processar();
          instante++;
        }
      }

      if (variavelReceptora == 0) {
        Continuar = 0;
      }

      cout << endl;
    }
  } catch (invalid_argument* e) {
    cout << "Erro: " << e->what();
    delete e;
  } catch (logic_error* e) {
    cout << "Erro: " << e->what() << endl;
    delete e;
  } catch (overflow_error* e) {
    cout << "Erro: " << e->what() << endl;
    delete e;
  } catch (underflow_error* e) {
    cout << "Erro: " << e->what() << endl;
    delete e;
  }  
  return 0;
}