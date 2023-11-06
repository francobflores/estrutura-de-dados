Pilha*criarPilha (size_t capacidade){
    Pilha *P = (Pilha*)calloc(1,sizeof(Pilha));
    if(P == NULL){
        printf("Erro de alocação");
        exit(1);
    }
    P->capacidade = capacidade;
    P->topo = -1;
    P->dado = (int *)calloc(P->capacidade, sizeof(int));
    if(P->dado == NULL){
        printf("Erro de alocação do Array");
        free(P);
        exit(1);
    }
    return P;
}

void destruirPilha (Pilha ** Pref){
    Pilha *P = *Pref;
    free(P->dado);
    free(P);
    *Pref = NULL;// Define o ponteiro como NULL para evitar referências a memória liberada

}

