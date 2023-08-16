#include <stdio.h>
#include <stdlib.h>

//Estrurura do nó
struct no{
    int chave;
    struct no* prox;
}

//Função que CRIA um nó
struct no* criaNo(int valor){
    struct no* novo;
    novo = (struct no*)malloc(sizeof(struct no));
    if(novo == NULL){
        printf("ERRO de alocação de memória ");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    return novo;
}
//Função que insere um nó no INICIO da lista
struct no* insereInicio(struct no* L, int valor ){
    struct no* novo = criaNo(valor);
    novo->prox = L;
    L = novo;
    return L;
}
int main(){
    return 0;
}