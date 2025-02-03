#include <stdio.h>
#include <string.h>

// Função recursiva para construir o percurso pós-fixo
void construirPosfixa(char *prefixo, char *infixo, int n, char *posfixa, int *index) {
    if (n <= 0) return; // Caso base: se não há nós, retorne

    // A raiz é o primeiro caractere do percurso prefixo
    char raiz = prefixo[0];

    // Encontre a posição da raiz no percurso infixo
    int pos;
    for (pos = 0; pos < n; pos++) {
        if (infixo[pos] == raiz) break;
    }

    // Construa a subárvore esquerda
    construirPosfixa(prefixo + 1, infixo, pos, posfixa, index);

    // Construa a subárvore direita
    construirPosfixa(prefixo + pos + 1, infixo + pos + 1, n - pos - 1, posfixa, index);

    // Adicione a raiz ao percurso pós-fixo
    posfixa[(*index)++] = raiz;
}

int main() {
    int C; // Número de casos de teste
    scanf("%d", &C); // Lê o número de casos de teste

    while (C--) {
        int N; // Número de nós
        char S1[53], S2[53]; // Percursos prefixo e infixo
        scanf("%d %s %s", &N, S1, S2); // Lê N, S1 e S2

        char posfixa[53] = ""; // String para armazenar o percurso pós-fixo
        int index = 0; // Índice para construir a string pós-fixa

        // Constrói o percurso pós-fixo
        construirPosfixa(S1, S2, N, posfixa, &index);
        posfixa[index] = '\0'; // Adiciona o terminador de string

        // Exibe o resultado
        printf("%s\n", posfixa);
    }

    return 0;
}