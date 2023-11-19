#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILIAIS 10
#define MAX_LIVROS 100

// Estrutura para representar um livro
typedef struct Livro {
    char isbn[20];
    char titulo[50];
    char autor[50];
    int quantidade;
} Livro;

// Estrutura para representar um nó da árvore binária de busca
typedef struct No {
    Livro livro;
    struct No* esquerda;
    struct No* direita;
} No;

// Estrutura para representar a árvore binária de busca
typedef struct ArvoreBinaria {
    No* raiz;
} ArvoreBinaria;

// Estrutura para representar uma filial
typedef struct Filial {
    int id;
    char endereco[100];
    char gerente[50];
    ArvoreBinaria estoque;
} Filial;

// Protótipos de função
No* criarNo(Livro livro);
No* inserirLivro(No* raiz, Livro livro);
void listarLivros(No* raiz);
void transferirEstoque(Filial* origem, Filial* destino, Filial filiais[], int* numFiliais);
void transferirLivros(No* raiz, Filial* destino);
Filial* buscarFilialPorId(Filial filiais[], int numFiliais, int id);
void imprimirArvore(No* raiz, int nivel);
void inserirNovoLivro(Filial* filial);
No* buscarLivroPorISBN(No* raiz, const char* isbn);
void imprimirLivro(Livro livro);
void buscarLivro(Filial* filial);
void excluirLivro(Filial* filial);
No* excluirLivroPorISBN(No* raiz, const char* isbn);
No* encontrarMinimo(No* raiz);
void removerFilial(Filial* filialRemover, Filial filiais[], int* numFiliais);

// Função para criar um novo nó da árvore
No* criarNo(Livro livro) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->livro = livro;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um livro na árvore binária de busca
No* inserirLivro(No* raiz, Livro livro) {
    if (raiz == NULL) {
        return criarNo(livro);
    }

    // Comparar ISBN para decidir em qual subárvore inserir
    int comparacao = strcmp(livro.isbn, raiz->livro.isbn);

    if (comparacao < 0) {
        raiz->esquerda = inserirLivro(raiz->esquerda, livro);
    } else if (comparacao > 0) {
        raiz->direita = inserirLivro(raiz->direita, livro);
    } else {
        // ISBN já existe, atualizar a quantidade
        raiz->livro.quantidade += livro.quantidade;
    }

    return raiz;
}
// Função para inserir um novo livro no estoque de uma filial
// Função para inserir um novo livro no estoque de uma filial
void inserirNovoLivro(Filial* filial) {
    Livro novoLivro;

    // Solicitar as informações do novo livro ao usuário
    printf("Informe o ISBN do novo livro: ");
    scanf("%19s", novoLivro.isbn);

    // Verificar se o ISBN já existe no estoque
    if (buscarLivroPorISBN(filial->estoque.raiz, novoLivro.isbn) != NULL) {
        printf("Livro com o ISBN %s já existe no estoque.\n", novoLivro.isbn);
        return;
    }

    printf("Informe o título do novo livro: ");
    getchar();  // Consumir a quebra de linha pendente no buffer
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = '\0';

    printf("Informe o autor do novo livro: ");
    fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = '\0';

    printf("Informe a quantidade de exemplares do novo livro: ");
    scanf("%lc", &novoLivro.quantidade);

    // Inserir o novo livro na árvore de busca
    filial->estoque.raiz = inserirLivro(filial->estoque.raiz, novoLivro);

    printf("Novo livro inserido com sucesso no estoque.\n");
}




// Função para listar os livros em ordem na árvore
void listarLivros(No* raiz) {
    if (raiz != NULL) {
        listarLivros(raiz->esquerda);
        printf("ISBN: %s, Título: %s, Autor: %s, Quantidade: %d\n", raiz->livro.isbn, raiz->livro.titulo, raiz->livro.autor, raiz->livro.quantidade);
        listarLivros(raiz->direita);
    }
}

// Função para transferir o estoque de uma filial para outra
void transferirEstoque(Filial* origem, Filial* destino, Filial filiais[], int* numFiliais) {
    // Percorrer a árvore de estoque da filial de origem e inserir cada livro na árvore de destino
    transferirLivros(origem->estoque.raiz, destino);
    // Após a transferência, pode-se limpar a árvore de estoque da filial de origem se desejado
    removerFilial(origem, filiais, numFiliais);
    // (isso depende dos requisitos específicos do seu sistema)
}

// Função auxiliar para remover uma filial da lista de filiais
void removerFilial(Filial* filialRemover, Filial filiais[], int* numFiliais) {
    for (int i = 0; i < *numFiliais; i++) {
        if (&filiais[i] == filialRemover) {
            // Movendo as filiais à frente na lista para preencher o espaço
            for (int j = i; j < *numFiliais - 1; j++) {
                filiais[j] = filiais[j + 1];
            }
            // Decrementar o número total de filiais
            (*numFiliais)--;
            printf("Filial %d encerrada e removida com sucesso.\n", filialRemover->id);
            return;
        }
    }
    printf("Erro ao remover a filial.\n");
}
// Função auxiliar para transferir os livros recursivamente
// Função para transferir os livros recursivamente
void transferirLivros(No* raiz, Filial* destino) {
    if (raiz != NULL) {
        // Transferir o livro apenas se ele não existir no destino
        if (buscarLivroPorISBN(destino->estoque.raiz, raiz->livro.isbn) == NULL) {
            destino->estoque.raiz = inserirLivro(destino->estoque.raiz, raiz->livro);
        }

        // Transferir os livros da subárvore esquerda
        transferirLivros(raiz->esquerda, destino);

        // Transferir os livros da subárvore direita
        transferirLivros(raiz->direita, destino);

        // Aqui, você pode optar por liberar a memória do nó atual se necessário
        // (isso depende dos requisitos específicos do seu sistema)
        // free(raiz);
    }
}


// Função para buscar uma filial por ID
Filial* buscarFilialPorId(Filial filiais[], int numFiliais, int id) {
    for (int i = 0; i < numFiliais; i++) {
        if (filiais[i].id == id) {
            return &filiais[i];
        }
    }
    return NULL;  // Retorna NULL se a filial não for encontrada
}

// Função para imprimir a árvore binária de busca (utilizando apenas o ISBN)
void imprimirArvore(No* raiz, int nivel) {
    if (raiz != NULL) {
        imprimirArvore(raiz->direita, nivel + 1);

        for (int i = 0; i < nivel; i++) {
            printf("\t");
        }

        printf("ISBN: %s\n", raiz->livro.isbn);

        imprimirArvore(raiz->esquerda, nivel + 1);
    }
}

// Função para buscar um livro por ISBN na árvore de estoque
No* buscarLivroPorISBN(No* raiz, const char* isbn) {
    if (raiz == NULL || strcmp(isbn, raiz->livro.isbn) == 0) {
        return raiz;
    }

    if (strcmp(isbn, raiz->livro.isbn) < 0) {
        return buscarLivroPorISBN(raiz->esquerda, isbn);
    } else {
        return buscarLivroPorISBN(raiz->direita, isbn);
    }
}

// Função para imprimir as informações de um livro
void imprimirLivro(Livro livro) {
    printf("ISBN: %s\n", livro.isbn);
    printf("Título: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Quantidade: %d\n", livro.quantidade);
}

// Função para realizar a operação de busca de um livro
void buscarLivro(Filial* filial) {
    char isbnBusca[20];

    // Solicitar o ISBN do livro ao usuário
    printf("Informe o ISBN do livro a ser buscado: ");
    scanf("%s", isbnBusca);

    // Buscar o livro na árvore de busca
    No* resultadoBusca = buscarLivroPorISBN(filial->estoque.raiz, isbnBusca);

    // Verificar se o livro foi encontrado
    if (resultadoBusca != NULL) {
        printf("Livro encontrado:\n");
        imprimirLivro(resultadoBusca->livro);
    } else {
        printf("Livro com o ISBN %s não encontrado no estoque.\n", isbnBusca);
    }
}

// Função para encontrar o nó mínimo em uma árvore (usada na exclusão)
// Função para encontrar o nó mínimo em uma árvore (usada na exclusão)
No* encontrarMinimo(No* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

// Função para excluir um livro pelo ISBN
No* excluirLivroPorISBN(No* raiz, const char* isbn) {
    if (raiz == NULL) {
        return raiz;
    }

    int comparacao = strcmp(isbn, raiz->livro.isbn);

    if (comparacao < 0) {
        raiz->esquerda = excluirLivroPorISBN(raiz->esquerda, isbn);
    } else if (comparacao > 0) {
        raiz->direita = excluirLivroPorISBN(raiz->direita, isbn);
    } else {
        // Nó com o livro encontrado
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No* temp = encontrarMinimo(raiz->direita);
        raiz->livro = temp->livro;
        raiz->direita = excluirLivroPorISBN(raiz->direita, temp->livro.isbn);
    }

    return raiz;
}
void excluirLivro(Filial* filial) {
    char isbnExcluir[20];

    // Solicitar o ISBN do livro a ser excluído ao usuário
    printf("Informe o ISBN do livro a ser excluído: ");
    scanf("%s", isbnExcluir);

    // Excluir o livro da árvore de busca
    filial->estoque.raiz = excluirLivroPorISBN(filial->estoque.raiz, isbnExcluir);

    printf("Livro com ISBN %s excluído do estoque.\n", isbnExcluir);
}


// Função principal do menu
void menuPrincipal() {
    int opcao;
    Filial filiais[MAX_FILIAIS];
    int numFiliais = 0;

    do {
        printf("\n----- Menu Principal -----\n");
        printf("(1) Listar os dados de todas as filiais\n");
        printf("(2) Listar os dados de uma filial\n");
        printf("(3) Criar nova filial\n");
        printf("(4) Encerrar atividades de uma filial\n");
        printf("(5) Realizar operações no estoque de uma filial\n");
        printf("(6) Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Listar os dados de todas as filiais
                for (int i = 0; i < numFiliais; i++) {
                    printf("Filial %d - Endereço: %s, Gerente: %s\n", filiais[i].id, filiais[i].endereco, filiais[i].gerente);
                }
                break;

             case 2:
                // Listar os dados de uma filial
                printf("Informe o ID da filial: ");
                int idFilial;
                scanf("%d", &idFilial);

                Filial* filialSelecionada = buscarFilialPorId(filiais, numFiliais, idFilial);

                if (filialSelecionada != NULL) {
                    printf("Filial %d - Endereço: %s, Gerente: %s\n", filialSelecionada->id, filialSelecionada->endereco, filialSelecionada->gerente);
                    printf("Livros em estoque:\n");
                    listarLivros(filialSelecionada->estoque.raiz);
                } else {
                    printf("Filial não encontrada.\n");
                }
                break;

            case 3:
                // Criar nova filial
                if (numFiliais < MAX_FILIAIS) {
                    printf("Informe o ID da nova filial: ");
                    scanf("%d", &filiais[numFiliais].id);

                    printf("Informe o endereço da nova filial: ");
                    scanf("%s", filiais[numFiliais].endereco);

                    printf("Informe o nome do gerente da nova filial: ");
                    scanf("%s", filiais[numFiliais].gerente);

                    // Inicializar a árvore de estoque da nova filial
                    filiais[numFiliais].estoque.raiz = NULL;

                    numFiliais++;
                    printf("Nova filial criada com sucesso.\n");
                } else {
                    printf("Limite máximo de filiais atingido.\n");
                }
                break;

            case 4:
                // Encerrar atividades de uma filial
                printf("Informe o ID da filial a ser encerrada: ");
                int idEncerrar;
                scanf("%d", &idEncerrar);

                Filial* filialEncerrar = buscarFilialPorId(filiais, numFiliais, idEncerrar);

                if (filialEncerrar != NULL) {
                    printf("Informe o ID da filial que receberá o estoque: ");
                    int idReceber;
                    scanf("%d", &idReceber);

                    Filial* filialReceber = buscarFilialPorId(filiais, numFiliais, idReceber);

                    if (filialReceber != NULL) {
                        // Transferir o estoque
                       transferirEstoque(filialEncerrar, filialReceber, filiais, &numFiliais);

                        // Imprimir os dados da filial que recebeu o estoque
                        printf("Filial %d - Endereço: %s, Gerente: %s\n", filialReceber->id, filialReceber->endereco, filialReceber->gerente);
                        printf("Livros em estoque:\n");
                        listarLivros(filialReceber->estoque.raiz);
                    } else {
                        printf("Filial que receberá o estoque não encontrada.\n");
                    }
                } else {
                    printf("Filial a ser encerrada não encontrada.\n");
                }
                break;

            case 5:
                // Realizar operações no estoque de uma filial
                printf("Informe o ID da filial: ");
                int idOperacoes;
                scanf("%d", &idOperacoes);

                Filial* filialOperacoes = buscarFilialPorId(filiais, numFiliais, idOperacoes);

                if (filialOperacoes != NULL) {
                    int opcaoOperacoes;

                    do {
                        printf("\n----- Operações no Estoque -----\n");
                        printf("(a) Imprimir a lista de livros em ordem crescente de ISBN\n");
                        printf("(b) Inserir um novo livro\n");
                        printf("(c) Buscar um livro no sistema\n");
                        printf("(d) Imprimir a estrutura da árvore binária de busca\n");
                        printf("(e) Excluir um livro\n");
                        printf("(f) Retornar ao menu principal\n");
                        printf("Escolha uma opção: ");
                        scanf(" %lc", &opcaoOperacoes);

                        switch (opcaoOperacoes) {
                            case 'a':
                                printf("Lista de livros em ordem crescente de ISBN:\n");
                                listarLivros(filialOperacoes->estoque.raiz);
                                break;

                            case 'b':
                                // Inserir um novo livro
                                inserirNovoLivro(filialOperacoes);
                                break;

                            case 'c':
                                // Buscar um livro no sistema
                                buscarLivro(filialOperacoes);
                                break;

                            case 'd':
                                printf("Estrutura da árvore binária de busca:\n");
                                imprimirArvore(filialOperacoes->estoque.raiz, 0);
                                break;

                            case 'e':
                                // Excluir um livro
                                excluirLivro(filialOperacoes);
                                break;

                            case 'f':
                                printf("Retornando ao menu principal.\n");
                                break;

                            default:
                                printf("Opção inválida. Tente novamente.\n");
                        }

                    } while (opcaoOperacoes != 'f');

                } else {
                    printf("Filial não encontrada.\n");
                }
                break;

            case 6:
                printf("Encerrando o programa. Até logo!\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 6);
}

int main() {
     Filial filiais[MAX_FILIAIS];
    int numFiliais = 0;
    menuPrincipal();  // Chama o menu principal para iniciar o programa

    // Libera a memória e realiza outras operações necessárias antes de encerrar o programa

    return 0;
}
