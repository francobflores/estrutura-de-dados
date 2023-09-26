#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

No *criaNo(int valor){
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro de alocação de memória!");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    return novo;
}

No *insereOrd(No *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L;
    No *pred = NULL;

    if(L == NULL)
        L = novo;
    else{
        while(aux != NULL && valor > aux->chave){
            pred = aux;
            aux = aux->prox;
        }
        
        //inserir no inicio
        if(pred == NULL){ 
            novo->prox = aux;
            L = novo;
        }else{
        //insere no meio ou no final
            novo->prox = aux;
            pred->prox = novo;
        }
    }
    return L;
}

void imprime(No *L){
    No *aux = L;
    if(L !=  NULL){
        while(aux != NULL){
            printf("%d ", aux->chave);
            aux = aux->prox;
        }
        printf("\n");
    }
}
int main(){
    No *L = NULL;

    L = insereOrd(L, 5);
    L = insereOrd(L, 4);
    L = insereOrd(L, 10);
    L = insereOrd(L, 2);
    L = insereOrd(L, 8);

    imprime(L);
    
    return 0;
}