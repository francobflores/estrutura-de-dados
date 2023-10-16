#include "pilha-estatica.h"

void inicializar (Pilha *stack){
    stack->top = -1;
}

int vazia(Pilha *stack){
    return stack->topo == -1; 
}

int cheia(Pilha *stack){
    return stack->topo == TAMANHO -1;
}

void push(Pilha* stack, int valor) {
    if (!cheia(stack)) {  // Verifica se a pilha não está cheia
        stack->topo++;  // Incrementa o topo
        stack->p[stack->topo] = valor;  // Adiciona o elemento ao topo
    } else {
        printf("Erro: A pilha está cheia!\n");
    }
}

void pop(Pilha *stack){
    if(!vazia(stack)){
        int valor = stack->p[stack->topo];
        stack->topo --;
        retorn valor;
    }else{
        printf("A pilha está vazia!\n");
        return -1;
    }
}
