#include <stdio.h>
#include <stdlib.h>

#define MAX_ROTEADORES 60
#define MAX_CABOS 200

typedef struct {
    int origem;
    int destino;
    int preco;
} Cabo;

int parent[MAX_ROTEADORES + 1]; // Array para armazenar o pai de cada roteador

// Função para encontrar o conjunto (raiz) de um roteador
int find(int i) {
    while (parent[i] != i) {
        parent[i] = parent[parent[i]]; // Compressão de caminho
        i = parent[i];
    }
    return i;
}

// Função para unir dois conjuntos
void union_sets(int i, int j) {
    int raiz_i = find(i);
    int raiz_j = find(j);
    parent[raiz_i] = raiz_j;
}

// Função de comparação para ordenar os cabos por preço
int comparar(const void *a, const void *b) {
    Cabo *cabo1 = (Cabo *)a;
    Cabo *cabo2 = (Cabo *)b;
    return cabo1->preco - cabo2->preco;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    Cabo cabos[MAX_CABOS];

    // Ler os cabos de internet
    for (int i = 0; i < C; i++) {
        scanf("%d %d %d", &cabos[i].origem, &cabos[i].destino, &cabos[i].preco);
    }

    // Ordenar os cabos por preço (custo)
    qsort(cabos, C, sizeof(Cabo), comparar);

    // Inicializar o array de pais (cada roteador é seu próprio pai)
    for (int i = 1; i <= R; i++) {
        parent[i] = i;
    }

    int custo_total = 0;
    int cabos_adicionados = 0;

    // Aplicar o Algoritmo de Kruskal
    for (int i = 0; i < C; i++) {
        int origem = cabos[i].origem;
        int destino = cabos[i].destino;

        // Verificar se a adição do cabo forma um ciclo
        if (find(origem) != find(destino)) {
            union_sets(origem, destino); // Unir os conjuntos
            custo_total += cabos[i].preco; // Adicionar o custo do cabo
            cabos_adicionados++;

            // Se todos os roteadores estão conectados, parar
            if (cabos_adicionados == R - 1) {
                break;
            }
        }
    }

    printf("%d\n", custo_total);

    return 0;
}