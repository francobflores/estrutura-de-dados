#include<stdio.h>
#include<stdlib.h>

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

No *insereInicio(No *L, int valor){
    No *novo = criaNo(valor);
    if(L == NULL) L = novo;
    else{
        novo->prox = L;
        L->ant = novo;
        L = novo;
    }
    return L;
}

void imprime(No *L){
    if(L != NULL){
        No *aux = L;
        while(aux != NULL){
            printf("%d ", aux->chave);
            aux = aux->prox;
        }
    }
    printf("\n");
}

int main(){
    No *L = NULL;

    L = insereInicio(L , 9);
    L = insereInicio(L , 9);
    L = insereInicio(L , 9);
    L = insereInicio(L , 9);
    L = insereInicio(L , 9);
    L = insereInicio(L , 9);
    L = insereInicio(L , 9);
    L = insereInicio(L , 9);

    imprime(L);
    
    return 0;
}