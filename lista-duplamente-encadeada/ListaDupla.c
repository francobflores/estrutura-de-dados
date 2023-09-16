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

No *insereFinal(No *L, int valor){
    No *novo = criaNo(valor);
    if(L == NULL) L= novo;
    else{
        No *aux = L;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        
        aux->prox = novo;
        novo->ant = aux;
    }
    return L;
}

void imprime(No *L){
    printf("Imprimindo a Lista:");
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
    int valor, escolha;
    while(1){
    printf("\nMenu:\n");
    printf("1. Inserir elemento no início\n");
    printf("2. Inserir elemento no final\n");
    printf("3. Imprimir Lista\n");
    printf("4. Sair do programa ");
    
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:/* constant-expression */
        /* code */
         printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                L = insereInicio(L, valor);
        break;
    case 2:
        printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
                L = insereFinal(L, valor);
        break;
    case 3:
            imprime(L);
            break;
    
    case 4: 
        printf("Fechando o Programa! By!");
        printf("\n");
        exit(0);
        break;
    default:
    printf("Opção inválida!\n");
        break;
    }
    }

    

    
    
    return 0;
}