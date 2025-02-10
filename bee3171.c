#include <stdio.h>

#define MAX 101

int parent[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
        parent[rootX] = rootY;
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    // Inicializa o vetor de pais, onde cada segmento é seu próprio representante
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    // Processa as ligações
    for (int i = 0; i < L; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        unite(X, Y);
    }

    // Verifica se todos os segmentos estão conectados
    int root = find(1);
    for (int i = 2; i <= N; i++) {
        if (find(i) != root) {
            printf("INCOMPLETO\n");
            return 0;
        }
    }

    printf("COMPLETO\n");
    return 0;
}
