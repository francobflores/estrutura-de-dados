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

//Função que exclui o primeiro nó da Lista

struct no* excluiIncio(struct no* L){
    struct no* aux = L;
    if(L == NULL)return NULL;
    L = L->prox;
    free(aux);
    return L;
}

//Função que exclui o último nó da Lista
 
struct no* excluiFinal(struct no* L){
    struct no* aux = L;
    struct no* pred = NULL;
    if(L == NULL)return NULL;
    else{
        while(aux->prox != NULL){
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL) L=NULL;
        else pred->prox = NULL;
        free(aux);
        return L;
    }
}

//Função que exclui uma chave na Lista

struct no* excluiChave(struct no *L, int valor){
    struct no* aux = L;
    struct no* pred = NULL;
    if( L == NULL)return NULL;
    else{
        while(aux != NULL && valor != aux->chave){
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL)L = aux->prox; // o valor a ser excluido é o primeiro na lista
        else pred->prox = aux->prox;
        free(aux);
        return L;
    }
}

//Função de busca em uma lista ordenada

struct no* buscaChaveOrdenado(struct no* L,int valor){
    struct no* aux = L;
    if(L == NULL)return NULL;
    else{
        while(aux != NULL){
            if(valor <= aux->chave) break;
            aux = aux->prox;
        }
        return aux; // ou vai retornar o valor ou retornar o primeiro valor maior que o buscado.
    }
}

//Função que insereOrdenado na Lista

struct no* insereOrdenado(struct no* L, int valor){
    struct no* novo =criaNo(valor);
    struct no* aux = L;
    struct no* pred =NULL;
    if(L == NULL)L = novo;
    else{
        while(aux != NULL && valor > aux->chave){
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL){
            novo->prox = aux;
            L = novo;
        }
        else{
            novo->prox = aux;
            pred->prox = novo;
        }
    }
    return L;
}

//função que exclui uma chave em uma lista ordenada

struct no* excluiChaveOrd(struct no* L, int valor){
    struct no* aux = L;
    struct no* pred = NULL;
    if(L == NULL)return NULL;
    else{
        while(aux != NULL && valor > aux->chave){
            pred = aux;
            aux = aux->prox;
        }
        if(aux != NULL && aux->chave == valor){
            if(pred == NULL)L = aux->prox;
            else pred->prox = aux->prox;
            free(aux);
        }
        return L;
    }
}

//Função de buscar ordenado auxiliar 

struct no *buscaListaOrd(struct no *L, int valor, struct no **pred) {
    struct no *aux = L;
    (*pred) = NULL;

    if (L == NULL) return NULL;
    else {
        while (aux != NULL) {
            if (valor <= aux->chave) break;
            (*pred) = aux;
            aux = aux->prox;
        }
        return aux;
    }
}


int main(){
   // printf("Testando a Função insereInicio():\n\n");
    
    struct no *L = NULL;
/*
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

    printf("Testando a função que exclui o primeiro nó da Lista:\n");
    L = excluiIncio(L);
    imprime(L);

    printf("Testando a função que exclui o último nó da Lista:\n");
    L = excluiFinal(K);
    imprime(K);
 */

printf("TESTE DAS FUNÇÕES ORDENADAS\n\n");

    L = insereOrdenado(L,20);
    L = insereOrdenado(L,80);
    L = insereOrdenado(L,70);
    L = insereOrdenado(L,30);
    L = insereOrdenado(L,90);
     imprime(L);
    
    L = excluiChaveOrd(L, 70);
    
    imprime(L);
    return 0;
}