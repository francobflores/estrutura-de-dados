#include "pilha-estatica.h"

void inicializar (Pilha *stack){
    stack->top = -1;
}

int vazia(Pilha *stack){
    return stack->topo == -1; 
}