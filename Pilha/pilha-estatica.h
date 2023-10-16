#ifndef __PILHA_H__
#define __PILHA_H__

/* Inclusão de bibliotecas necessárias para o pacote */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definição de estruturas e declaração de variáveis locais */
#define TAMANHO 5  // Tamanho máximo da pilha

struct pilha {
    int p[TAMANHO];  // Array para armazenar os elementos
    int topo;  // Índice do elemento no topo
}Pilha;




#endif