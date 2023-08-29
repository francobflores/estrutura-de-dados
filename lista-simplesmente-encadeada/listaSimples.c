#include <stdio.h>
#include <stdlib.h>

//Estrurura do nó
struct no{
    int chave;
    struct no* prox;
};

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
//Função que insere um nó no FINAL da lista
struct no* insereFinal(struct no*L, int valor){
    struct no* novo = criaNo(valor);
    struct no* aux = L;
    if(L == NULL)
        L = novo;
    else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return L;
}
//Função que BUSCA uma chave na lista
struct no* buscaChave(struct no* L, int chave){
    struct no* aux = L;
    if(L == NULL)return NULL;
    while(aux != NULL){
        if(aux->chave == chave)break;
        aux = aux->prox;
    }
    return aux;
}
//Função que IMPRIME uma lista
void imprime(struct no* L){
    struct no* aux = L;
    printf("Imprimindo Lista:\n");
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}


int main(){
    printf("Testando a Função insereInicio():\n\n");
    
    struct no *L = NULL;

    L = insereInicio(L, 20);
    L = insereInicio(L, 70);
    L = insereInicio(L, 90);

    imprime(L);

    printf("Testando a Função insereFinal():\n\n");

    struct no *K = NULL;

    K = insereFinal(K, 20);
    K = insereFinal(K, 70);
    K = insereFinal(K, 90);

    imprime(K);

    printf("Buscando uma chave na Lista:\n");
    struct no *valorBuscado = buscaChave(L,0);
    if(valorBuscado == NULL){
        printf("Chave não encontrada!\n");    
    }
    else{
        printf("Chave %d encotrada!\n",valorBuscado->chave);
    }
    
    return 0;
}