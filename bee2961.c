#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N); // Lê o número de anos

    int erros[5] = {0}; // Array para contar os erros em cada categoria (1 a 4)

    for (int ano = 0; ano < N; ano++) {
        char palavra[10];
        scanf("%s", palavra); // Lê "Palpites"

        char palpites[4][101]; // Array para armazenar os palpites
        for (int i = 0; i < 4; i++) {
            scanf(" %[^\n]", palpites[i]); // Lê os palpites
        }

        scanf("%s", palavra); // Lê "Vencedores"

        char vencedores[4][101]; // Array para armazenar os vencedores
        for (int i = 0; i < 4; i++) {
            scanf(" %[^\n]", vencedores[i]); // Lê os vencedores
        }

        // Compara palpites com vencedores e conta os erros
        for (int i = 0; i < 4; i++) {
            if (strcmp(palpites[i], vencedores[i]) != 0) {
                erros[i + 1]++; // Incrementa o contador de erros da categoria (1 a 4)
            }
        }
    }

    // Encontra a categoria com mais erros
    int max_erros = 0;
    for (int i = 1; i <= 4; i++) {
        if (erros[i] > max_erros) {
            max_erros = erros[i];
        }
    }

    // Exibe as categorias com mais erros
    int primeiro = 1; // Flag para controlar o espaço entre as categorias
    for (int i = 1; i <= 4; i++) {
        if (erros[i] == max_erros) {
            if (!primeiro) {
                printf(" "); // Adiciona espaço entre as categorias
            }
            printf("%d", i);
            primeiro = 0; // Marca que já foi impressa a primeira categoria
        }
    }
    printf("\n"); // Quebra de linha no final

    return 0;
}