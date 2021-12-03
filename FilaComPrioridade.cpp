#include <iostream>
#include <stdexcept>
#include "FilaComPrioridade.h"

FilaComPrioridade::FilaComPrioridade(int tamanho) : Fila(tamanho){
  somaPrioridades = 0;
}


FilaComPrioridade::~FilaComPrioridade() {
}

void FilaComPrioridade::enqueue (Datagrama *d, bool prioritario){
  if (quantidade != tamanho) {

    if (prioritario == false) { /*Adicionar um datagrama normal*/
      fila[fim] = d;

      if (fim == tamanho-1) {
        fim = 0;
      } else {
        fim++;
      }
        quantidade++;
    } else {
        int anterior;/*Define-se o anterior*/
        int posicao;

        if (fim == 0) {
            anterior = tamanho-1;
        } else {
            anterior = fim-1;
        }

        fila[fim] = d; /*Adiciona-se normalmente o datagrama*/
        posicao = fim; /*Guardando a posição*/
        vetorPrioridades[posicao] = somaPrioridades + 1; /*Adicionando prioridade*/

        if (fim == tamanho-1) {
            fim = 0;
        } else {
            fim++;
        }

        int passador = 0;

        while (passador < quantidade) {
            if (vetorPrioridades[anterior] > vetorPrioridades[posicao])
            {
                int memoriaPrioridade;
                Datagrama* memoriaDatagrama;

                memoriaDatagrama = fila[anterior]; /*Invertendo os datagramas*/
                fila[anterior] = fila[posicao];
                fila[posicao] = memoriaDatagrama;

                memoriaPrioridade = vetorPrioridades[anterior]; /*Invertendo as prioridades*/
                vetorPrioridades[anterior] = vetorPrioridades[posicao];
                vetorPrioridades[posicao] = memoriaPrioridade;

                posicao = anterior; /*Atualizando a posicao de verificação e o respectivo anterior*/

                if (posicao == 0) {
                    anterior = tamanho-1;
                } else {
                    anterior = posicao-1;
                }
            } else {
                passador = quantidade; /*Já achou a posição correta, então pode sair do laço*/
            }
            passador++;
        }
        quantidade++;
    }

  } else {
    throw new overflow_error ("A fila com prioridade esta cheia");
  }

}
