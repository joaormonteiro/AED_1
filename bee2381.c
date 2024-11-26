#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // Aloca espaço para ponteiros de nomes
    char *nomes[n];

    // Lê os nomes e aloca memória dinamicamente
    for (int i = 0; i < n; i++) {
        nomes[i] = (char *)malloc(21 * sizeof(char)); // Máximo de 20 caracteres + '\0'
        if (nomes[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memória\n");
            return 1;
        }
        scanf("%s", nomes[i]);
    }

    // Ordena os nomes em ordem alfabética
    qsort(nomes, n, sizeof(char *), comparar);

    // Imprime o K-ésimo nome (índice K-1 porque arrays são 0-indexados)
    printf("%s\n", nomes[k - 1]);

    // Libera a memória alocada
    for (int i = 0; i < n; i++) {
        free(nomes[i]);
    }

    return 0;
}
