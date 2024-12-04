#include <stdio.h>
#include <string.h>

int contarDiamantes(const char *linha) {
    int diamantes = 0;
    int pilha = 0; // Representa a quantidade de '<' não emparelhados

    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '<') {
            pilha++; // Adiciona um possível início de diamante
        } else if (linha[i] == '>') {
            if (pilha > 0) {
                diamantes++; // Encontra um par '<>'
                pilha--;     // Remove o '<' correspondente
            }
        }
    }

    return diamantes;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // Consome o '\n' após o número de casos

    for (int i = 0; i < n; i++) {
        char linha[1001];
        fgets(linha, 1001, stdin);

        // Remove o caractere '\n' ao final, se existir
        linha[strcspn(linha, "\n")] = '\0';

        int diamantes = contarDiamantes(linha);
        printf("%d\n", diamantes);
    }

    return 0;
}
