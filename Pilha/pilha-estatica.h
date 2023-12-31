#ifndef __PILHA_H__
#define __PILHA_H__

/* Inclusão de bibliotecas necessárias para o pacote */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/* Definição de estruturas e declaração de variáveis locais */
#define TAMANHO 5  // Tamanho máximo da pilha

typedef struct pilha {
    int *dado;
    size_t capacidade; 
    int topo;  // Índice do elemento no topo
}Pilha;

/*Função que inicializa uma pilha*/
Pilha *criarPilha (size_t capacidade);

void destruirPilha (Pilha ** Pref);

/*Função para verificar se a pilha está vazia*/
// Retorna 1 (verdadeiro) se o topo for -1, indicando que a pilha está vazia. Caso contra 0
//int vazia(Pilha *stack);

/*Função que verifica se a pilha está cheia*/
// Retorna 1 (verdadeiro) se o topo atingiu o tamanho máximo da pilha
//int cheia(Pilha *stack);

//Função que insere um elemento no topo da pilha
//void push(Pilha* stack, int valor);

//Função que remove o elemento do topo da pilha
//void pop(Pilha *stack);

// Função para obter o elemento no topo da pilha (peek)
//int peek(Pilha* stack);






#endif