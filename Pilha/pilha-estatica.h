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

/*Função que inicializa uma pilha*/
void inicializar (Pilha *stack);

/*Função para verificar se a pilha está vazia*/
// Retorna 1 (verdadeiro) se o topo for -1, indicando que a pilha está vazia. Caso contra 0
int vazia(Pilha *stack);

/*Função que verifica se a pilha está cheia*/
// Retorna 1 (verdadeiro) se o topo atingiu o tamanho máximo da pilha
int cheia(Pilha *stack);

//Função que insere um elemento no topo da pilha
void push(Pilha* stack, int valor);

//Função que remove o elemento do topo da pilha
void pop(Pilha *stack);





#endif