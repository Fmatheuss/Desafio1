#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    unsigned char armarios = 0; // Inicialmente todos os armários livres
    int opcao, armario;

    srand(time(NULL)); // Inicializa a semente para números aleatórios

    do {
        printf("\nMenu:\n");
        printf("1. Ocupar armario\n");
        printf("2. Liberar armario\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                do {
                    armario = rand() % 8; // Gera um número aleatório entre 0 e 7
                } while (armarios & (1 << armario)); // Verifica se o armário já está ocupado
                armarios |= (1 << armario); // Ocupa um armário
                printf("Armario %d ocupado.\n", armario + 1);
                break;
            case 2:
                printf("Digite o numero do armario a ser liberado (1-8): ");
                scanf("%d", &armario);
                if (armario >= 1 && armario <= 8) {
                    armarios &= ~(1 << (armario - 1)); // Libera o armário selecionado
                    printf("Armario %d liberado.\n", armario);
                } else {
                    printf("Numero de armario invalido.\n");
                }
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

        // Exibe o estado dos armários (opcional)
        printf("Estado dos armarios: ");
        for (int i = 7; i >= 0; i--) {
            printf("%d", (armarios >> i) & 1);
        }
        printf("\n");

    } while (opcao != 3);

    return 0;
}