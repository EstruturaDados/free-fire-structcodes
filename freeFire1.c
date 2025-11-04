#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura que representa um item da mochila
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n==============================\n");
        printf("MOCHILA FREE FIRE - NIVEL AVENTUREIRO\n");
        printf("==============================\n");
        printf("Itens na mochila: (%d/%d)\n", totalItens, MAX_ITENS);
        printf("\n 1️ Adicionar item");
        printf("\n 2️ Remover item");
        printf("\n 3️ Listar itens");
        printf("\n 4️ Buscar item por nome");
        printf("\n 0️ Sair");
        printf("\n------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa buffer do teclado

        switch (opcao) {
            case 1: {
                if (totalItens >= MAX_ITENS) {
                    printf("\n Mochila cheia! Não é possivel adicionar mais itens.\n");
                } else {
                    printf("\n Adicionar novo item\n");
                    printf("Nome do item: ");
                    fgets(mochila[totalItens].nome, 50, stdin);
                    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0'; // remove \n

                    printf("Tipo do item: ");
                    fgets(mochila[totalItens].tipo, 30, stdin);
                    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0';

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    getchar();

                    totalItens++;
                    printf("\n Item adicionado com sucesso!\n");
                }
                break;
            }

            case 2: {
                if (totalItens == 0) {
                    printf("\n Nenhum item para remover.\n");
                } else {
                    char nomeRemover[50];
                    printf("\n Digite o nome do item a remover: ");
                    fgets(nomeRemover, 50, stdin);
                    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                    int encontrado = 0;
                    for (int i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            // Move os itens seguintes uma posição para trás
                            for (int j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            totalItens--;
                            encontrado = 1;
                            printf("\n Item '%s' removido com sucesso!\n", nomeRemover);
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("\n Item não encontrado.\n");
                    }
                }
                break;
            }

            case 3: {
                printf("\n ITENS NA MOCHILA (%d/%d):\n", totalItens, MAX_ITENS);
                printf("----------------------------------------\n");
                if (totalItens == 0) {
                    printf("Mochila vazia.\n");
                } else {
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Qtd");
                    printf("----------------------------------------\n");
                    for (int i = 0; i < totalItens; i++) {
                        printf("%-20s %-15s %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                }
                break;
            }

            case 4: {
                if (totalItens == 0) {
                    printf("\n Nenhum item para buscar.\n");
                } else {
                    char nomeBusca[50];
                    printf("\n Digite o nome do item que deseja buscar: ");
                    fgets(nomeBusca, 50, stdin);
                    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                    int encontrado = 0;
                    for (int i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                            printf("\n ITEM ENCONTRADO!\n");
                            printf("------------------------------\n");
                            printf("Nome: %s\n", mochila[i].nome);
                            printf("Tipo: %s\n", mochila[i].tipo);
                            printf("Quantidade: %d\n", mochila[i].quantidade);
                            printf("------------------------------\n");
                            encontrado = 1;
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("\n Item não encontrado na mochila.\n");
                    }
                }
                break;
            }

            case 0:
                printf("\n Saindo do jogo... Ate a proxima partida!\n");
                break;

            default:
                printf("\n Opcao invalida, tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
