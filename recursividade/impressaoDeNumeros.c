#include<stdio.h>

void imprimeDecrescente(int x ){
    if(x == 0)
    printf("%d  \n", x);
    else{
        printf("%d ",x);
        imprimeDecrescente(x-1);
    }
}

void imprimeCrescente(int y){
    if(y == 0)
        printf("%d ", y);
    else{
        imprimeCrescente(y-1);
        printf("%d ", y);
    }

    
}

int main(){
    int n;
    printf("Digite um numero inteiro:");
    scanf("%d", &n);
    printf("Forma decrescente:\n");
    imprimeDecrescente(n);
    printf("\n");
    printf("Forma crescente:\n");
    imprimeCrescente(n);
    printf("\n");
    return 0;
}