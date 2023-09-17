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

No *excluiInicio(No *L){
    No *aux = L;
    if(L == NULL)return L;
    L = L->prox;
    if(aux->ant != NULL) //verifica se a lista só tem um elemento
    L->ant = NULL;// este campo nao pode ser acessado caso seja elemento unico
    free(aux);
    return L;
}

No *excluiFinal(No *L){
    No *aux = L;
    if(L == NULL)return L;
    while(aux->prox != NULL)
        aux = aux->prox;
    if(aux->ant == NULL){
    L = L->prox;
    }
    else{
        aux->ant->prox = aux->prox;
    }
    free(aux);
    return L;
}

No *buscaChave(No *L, int valor){
    No *aux = L;
    if(L == NULL)return aux;
    while(aux != NULL){
        if(aux->chave == valor)break;
        aux = aux->prox;
    }
    return aux;
}
void imprime(No *L){
    printf("Imprimindo a Lista:\n");
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
    printf("3. Excluir primeiro elemento\n");
    printf("4. Excluir o último elemento\n");
    printf("5. Buscar uma chave na lista\n");
    printf("7. Imprimir Lista\n");
    printf("8. Sair do programa\n");
    
    printf("Escolha uma das opções: ");
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
        L = excluiInicio(L);
        
        break;
    case 4:
        L = excluiFinal(L);
        break;
    case 5:
        No *buscador;
        printf("Informe a chave do elemento a ser buscado:\n");
        scanf("%d", &valor);
        buscador = buscaChave(L, valor);
        if(buscador != NULL){
            printf("Elemento %d Encontrado na Lista!",buscador->chave);
        }else{
            printf("Elemento não Encontrado na Lista!");
        }
        break;

    case 7:
            imprime(L);
            break;
    
    case 8: 
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