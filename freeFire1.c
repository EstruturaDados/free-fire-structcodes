#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
// finalizado novato/aventureiro
// Estrutura para representar um item da mochila
typedef struct {
    char nome[50];
    char tipo[50];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int total = 0;  // Quantidade atual de itens
    int opcao;

    do {
        printf("\n=== MOCHILA DO FREE FIRE ===\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item por nome\n"); // nível aventureiro
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer do teclado

        switch(opcao) {
            case 1: {
                if (total >= MAX_ITENS) {
                    printf(" Mochila cheia! Nao é possivel adicionar mais itens.\n");
                } else {
                    printf("\nDigite o nome do item: ");
                    fgets(mochila[total].nome, 50, stdin);
                    mochila[total].nome[strcspn(mochila[total].nome, "\n")] = '\0'; // remove \n

                    printf("Digite o tipo do item: ");
                    fgets(mochila[total].tipo, 50, stdin);
                    mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = '\0';

                    printf("Digite a quantidade: ");
                    scanf("%d", &mochila[total].quantidade);
                    getchar();

                    total++;
                    printf(" Item adicionado com sucesso!\n");
                }
                break;
            }

            case 2: {
                if (total == 0) {
                    printf(" Nenhum item para remover.\n");
                } else {
                    char nomeRemover[50];
                    printf("\nDigite o nome do item que deseja remover: ");
                    fgets(nomeRemover, 50, stdin);
                    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                    int encontrado = 0;
                    for (int i = 0; i < total; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            for (int j = i; j < total - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            total--;
                            encontrado = 1;
                            printf(" Item removido com sucesso!\n");
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf(" Item não encontrado.\n");
                    }
                }
                break;
            }

            case 3: {
                if (total == 0) {
                    printf("\n Mochila vazia.\n");
                } else {
                    printf("\n Itens na mochila:\n");
                    printf("------------------------------------------\n");
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("------------------------------------------\n");

                    for (int i = 0; i < total; i++) {
                        printf("%-20s %-15s %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }

                    printf("------------------------------------------\n");
                }
                break;
            }

            case 4: { // Nível aventureiro — busca por nome
                if (total == 0) {
                    printf(" Mochila vazia. Nenhum item para buscar.\n");
                } else {
                    char nomeBusca[50];
                    printf("\nDigite o nome do item que deseja buscar: ");
                    fgets(nomeBusca, 50, stdin);
                    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                    int encontrado = 0;
                    for (int i = 0; i < total; i++) {
                        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                            printf("\n Item encontrado:\n");
                            printf("Nome: %s\n", mochila[i].nome);
                            printf("Tipo: %s\n", mochila[i].tipo);
                            printf("Quantidade: %d\n", mochila[i].quantidade);
                            encontrado = 1;
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf(" Item '%s' não encontrado na mochila.\n", nomeBusca);
                    }
                }
                break;
            }

            case 0:
                printf("\n Saindo do jogo... Ate a proxima partida!\n");
                break;

            default:
                printf(" Opção invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
