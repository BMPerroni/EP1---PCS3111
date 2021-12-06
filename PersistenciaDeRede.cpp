#include <iostream>
#include <stdexcept>
#include <fstream>
#include "PersistenciaDeRede.h"
#include "RoteadorComQoS.h"
#include "Hospedeiro.h"

PersistenciaDeRede::PersistenciaDeRede(string arquivo) : arquivo(arquivo) {
rede = new Rede();
}

PersistenciaDeRede::~PersistenciaDeRede() {

}

Rede* PersistenciaDeRede::carregar() {
  ifstream entrada;
  entrada.open(arquivo);

  if (entrada.fail()) {
    entrada.close();
    throw new logic_error ("Arquivo não encontrado!");
  }

  int quantidadeRoteadores; /*ROTEADORES*/

  entrada >> quantidadeRoteadores;
  if (!entrada.good()) {
    entrada.close();
    throw new logic_error ("Entrada invalida!");
  }
  for (int m = 0; m < quantidadeRoteadores ; m++) {
    string identificadorRot;
    entrada >> identificadorRot;

    if (!entrada.good() && (identificadorRot == "r" || identificadorRot == "q")) {
      entrada.close();
      throw new logic_error ("Entrada invalida!");
    }

    if (identificadorRot == "r") {
      int endereco;

      entrada >> endereco;

      if (!entrada.good()) {
        entrada.close();
        throw new logic_error ("Entrada invalida!");
      }
      Roteador* r = new Roteador(endereco);
      rede->adicionar(r);
    }

    if (identificadorRot == "q") {
      int endereco;
      entrada >> endereco;

      if (!entrada.good()) {
        entrada.close();
        throw new logic_error ("Entrada invalida!");
      }
      RoteadorComQoS* r = new RoteadorComQoS(endereco);

      int quantidadeDestinos;

      entrada >> quantidadeDestinos;

      if (!entrada.good()) {
        entrada.close();
        throw new logic_error ("Entrada invalida!");
      }

      for (int n = 0; n < quantidadeDestinos ; n++) {
        int destino;

        entrada >> destino;

        if (!entrada.good()) {
          throw new logic_error ("Entrada invalida!");
        }
        r->priorizar(destino);
      }
      rede->adicionar(r);
    } 
  }
  int quantidadeHospedeiros; /*HOSPEDEIROS*/
  
  entrada >> quantidadeHospedeiros;

  if (!entrada.good()) {
    throw new logic_error ("Entrada invalida!");
  }

  for (int z = 0; z < quantidadeHospedeiros; z++) {
    int endereco;
    int enderecoGat;
    int atraso;

    entrada >> endereco;
    if (!entrada.good()) {
      entrada.close();
      throw new logic_error ("Entrada invalida!");
    }
      
    entrada >> enderecoGat;

    if (!entrada.good()) {
      entrada.close();
      throw new logic_error ("Entrada invalida!");
    } 

    entrada >> atraso;
    if (!entrada.good()) {
      entrada.close();
      throw new logic_error ("Entrada invalida!");
    }

    Roteador *gateway = dynamic_cast<Roteador*>(rede->getNo(enderecoGat));

    Hospedeiro* h = new Hospedeiro(endereco, gateway, atraso);

    int quantidadeChat;

    entrada >> quantidadeChat;
    if (!entrada.good()) {
      entrada.close();
      throw new logic_error ("Entrada invalida!");
    }

    for (int i = 0; i < quantidadeChat; i++) {
      int porta;
      int enderecoDestino;
      int portaDestino;

      entrada >> porta;
      if (!entrada.good()) {
        entrada.close();
        throw new logic_error ("Entrada invalida!");
      }
          
      entrada >> enderecoDestino;
      if (!entrada.good()) {
        entrada.close();
        throw new logic_error ("Entrada invalida!");
      }
      
      entrada >> portaDestino;
      if (!entrada.good()) {
        entrada.close();
        throw new logic_error ("Entrada invalida!");
      }

      h->adicionarChat(porta, enderecoDestino, portaDestino);
    }
    rede->adicionar(h);
  }
  for (int g = 0; g < quantidadeRoteadores; g++) { /*TABELA DE REPASSE*/
  
    int roteador;
    int roteadorPadrao;
    int atrasoPadrao;
    int quantidadeMapeamentos;

    entrada >> roteador;
    if (!entrada.good()) {
      entrada.close();
      throw new logic_error ("Entrada invalida!");
    }

    entrada >> roteadorPadrao;
    if (!entrada.good()) {
      entrada.close();
      throw new logic_error ("Entrada invalida!");
    }

    entrada >> atrasoPadrao;
    if (!entrada.good()) {
      entrada.close();
      throw new logic_error ("Entrada invalida!");
    }

    entrada >> quantidadeMapeamentos;
    if (!entrada.good()) {
      entrada.close();
      throw new logic_error ("Entrada invalida!");
    }
    Roteador *roteadorConvertido = dynamic_cast<Roteador*>(rede->getNo(roteador));
    
    Roteador *roteadorPadraoConvertido = dynamic_cast<Roteador*>(rede->getNo(roteadorPadrao));
        
    roteadorConvertido->setPadrao(roteadorPadraoConvertido, atrasoPadrao);
    ;
    for (int j = 0; j < quantidadeMapeamentos; j++) {
      int enderecoDestino;
      int noAdjacente;
      int atrasoMapeamento;

      entrada >> enderecoDestino;
      if (!entrada.good()) {
        entrada.close();
        throw new logic_error ("Entrada invalida!");
      }

      entrada >> noAdjacente;
      if (!entrada.good()) {
        entrada.close();
        throw new logic_error ("Entrada invalida!");
      }

      entrada >> atrasoMapeamento;
      if (!entrada.good()) {
        entrada.close();
        throw new logic_error ("Entrada invalida!");
      }
      roteadorConvertido->mapear(enderecoDestino, rede->getNo(noAdjacente), atrasoMapeamento);
    }
  }
  return rede;
}

