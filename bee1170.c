#include <stdio.h>

int main() {
    int N; // Número de casos de teste
    scanf("%d", &N); // Lê o número de casos de teste

    for (int i = 0; i < N; i++) {
        double C; // Quantidade de comida
        scanf("%lf", &C); // Lê a quantidade de comida

        int dias = 0; // Contador de dias

        // Enquanto a comida for maior que 1 kg
        while (C > 1.0) {
            C /= 2.0; // Blobs come metade da comida
            dias++;   // Incrementa o contador de dias
        }

        // Exibe o resultado
        printf("%d dias\n", dias);
    }

    return 0;
}