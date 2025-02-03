#include <stdio.h>

int main() {
    double raio, area;
    const double pi = 3.14159; // Definindo o valor de pi

    // Lendo o valor do raio
    scanf("%lf", &raio);

    // Calculando a área
    area = pi * (raio * raio);

    // Exibindo o resultado formatado com 4 casas decimais
    printf("A=%.4lf\n", area);

    return 0;
}