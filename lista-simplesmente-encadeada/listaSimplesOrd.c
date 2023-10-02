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

No *removeChaveOrd(No *L, int ch){
    No *aux = L;
    No *pred = NULL;
    if(L == NULL){
        printf("Não foi posível excluir pois a chave nao se encontra na lista, ou melhor a lista se encontra vazia");
        return NULL;
    }
    while(aux != NULL && ch > aux->chave){
        pred = aux;
        aux = aux->prox;
    }
    if(aux != NULL && ch == aux->chave){
        if(pred == NULL) L = L->prox;
        else pred->prox = aux->prox;
        free(aux);
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

No *buscaChave(No *L, int valor){
    No *aux = L;
    if(L == NULL)return NULL;
    else{
        while(aux != NULL){
            if(valor <= aux->chave) aux = aux->prox;
        }
        return aux;
    }
}
/*int main(){
    No *L = NULL;
    No *K = NULL;
    L = insereOrd(L, 5);
    L = insereOrd(L, 4);
    L = insereOrd(L, 10);
    L = insereOrd(L, 2);
    L = insereOrd(L, 8);
    printf("Completa: ");
    imprime(L);

    L = removeChaveOrd(L, 2);
    printf("Remoção do menor: ");
    imprime(L);

    L= removeChaveOrd(L, 10);
    printf("Remoção do maior: ");
    imprime(L);
    
    L = removeChaveOrd(L, 5);
    printf("Remoção no meio da lista: ");
    imprime(L);
    printf("Teste da lista vazia: ");
    K = removeChaveOrd(K, 10);   
    return 0;
}*/

int main(){
    No * L = NULL;
    int opc;
    int chave;

    while(1){
        
        printf("==========MENU==========\n");
        printf("1. Inserir Ordenado!\n");
        printf("2. Remover Ordenado!\n");
        printf("3. Imprimir!\n");
        printf("9. Para fechar o Programa!\n");
        printf("Escolha uma das opções: ");
        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("Escolha a Chave a ser inserida: ");
            scanf("%d", &chave);
            L = insereOrd(L, chave);
            break;
        case 2:
            printf("Escolha a Chave a ser excluída: ");
            scanf("%d", &chave);
            L = removeChaveOrd(L, chave);
            break;
        case 3:
            printf("Impressão da Lista: ");
            imprime(L);
            break;
        case 9:
            printf("Fechando o Programa!\n");
            exit(1);
            break;

        
        default:
            break;
        }
        


        
    }

    return 0;
}