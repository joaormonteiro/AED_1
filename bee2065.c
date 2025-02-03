#include <stdio.h>
#include <limits.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M); // Lê N e M

    int v[N]; // Tempo por item de cada funcionário
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]); // Lê os tempos dos funcionários
    }

    int c[M]; // Número de itens de cada cliente
    for (int j = 0; j < M; j++) {
        scanf("%d", &c[j]); // Lê os itens dos clientes
    }

    int tempo[N]; // Tempo de disponibilidade de cada funcionário
    for (int i = 0; i < N; i++) {
        tempo[i] = 0; // Inicializa todos os funcionários como disponíveis no tempo 0
    }

    // Para cada cliente, atribui ao funcionário disponível mais cedo
    for (int j = 0; j < M; j++) {
        int funcionario = 0; // Assume que o primeiro funcionário é o mais disponível
        for (int i = 1; i < N; i++) {
            if (tempo[i] < tempo[funcionario]) {
                funcionario = i; // Encontra o funcionário com menor tempo de disponibilidade
            }
        }

        // Atualiza o tempo de disponibilidade do funcionário
        tempo[funcionario] += v[funcionario] * c[j];
    }

    // Encontra o maior tempo de disponibilidade entre os funcionários
    int total = 0;
    for (int i = 0; i < N; i++) {
        if (tempo[i] > total) {
            total = tempo[i];
        }
    }

    // Exibe o tempo total
    printf("%d\n", total);

    return 0;
}   