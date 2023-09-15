#include<stdio.h>

typedef struct no {
    int chave;
    struct no *prox;
    struct no *ant;
}No;

No *criaNo(int valor){
No *novo = (No*)malloc(sizeof(No));
if(novo == NULL){
    printf("Erro de alocação de memória! \n");
    exit(1);
}
novo->chave = valor;
novo->prox = NULL;
novo->ant = NULL;
return novo;
}