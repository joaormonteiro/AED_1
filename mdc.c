#include <stdio.h>

int mdc(int a, int b) {
    // Função para calcular o máximo divisor comum (MDC) usando o algoritmo de
    // Euclides
    if (b == 0) {
        return a;  // Se b for 0, o MDC é a
    }
    return mdc(b, a % b);  // Chamada recursiva com os valores trocados
}

int main() {
    int a, b;  // Variáveis para armazenar os dois números

    // Lê os dois números
    scanf("%d %d", &a, &b);

    // Calcula o MDC e exibe o resultado
    printf("%d\n", mdc(a, b));

    return 0;
}