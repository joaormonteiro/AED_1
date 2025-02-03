#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 300

// Função para calcular o número máximo de ligações
int maxLigacoes(const char *rna) {
    int stack[MAX_LENGTH]; // Pilha para guardar as bases
    int top = -1;         // Topo da pilha
    int ligacoes = 0;

    for (int i = 0; rna[i] != '\0'; i++) {
        char base = rna[i];

        if (top >= 0) {
            // Verifica se o par no topo da pilha é válido
            if ((stack[top] == 'B' && base == 'S') || (stack[top] == 'S' && base == 'B') ||
                (stack[top] == 'C' && base == 'F') || (stack[top] == 'F' && base == 'C')) {
                top--; // Remove o par da pilha
                ligacoes++;
            } else {
                stack[++top] = base; // Adiciona a base na pilha
            }
        } else {
            stack[++top] = base; // Adiciona a base na pilha
        }
    }

    return ligacoes;
}

int main() {
    char rna[MAX_LENGTH + 1];

    // Lê cada linha da entrada até EOF
    while (scanf("%s", rna) != EOF) {
        int resultado = maxLigacoes(rna);
        printf("%d\n", resultado);
    }

    return 0;
}
