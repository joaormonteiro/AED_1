#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

// Função para comparar as arestas pelo peso
int cmp(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

// Função do Union-Find para encontrar a raiz do conjunto
int find(int *parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent,     parent[x]); // Path compression
    return parent[x];
}

// Função para unir dois conjuntos no Union-Find
void union_sets(int *parent, int *rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int M, N;
    
    while (scanf("%d %d", &M, &N) && (M || N)) {
        Edge edges[N];

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        // Ordena as arestas pelo peso
        qsort(edges, N, sizeof(Edge), cmp);

        int parent[M], rank[M];
        for (int i = 0; i < M; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int mstCost = 0, edgesUsed = 0;
        for (int i = 0; i < N && edgesUsed < M - 1; i++) {
            if (find(parent, edges[i].u) != find(parent, edges[i].v)) {
                union_sets(parent, rank, edges[i].u, edges[i].v);
                mstCost += edges[i].w;
                edgesUsed++;
            }
        }

        printf("%d\n", mstCost);
    }

    return 0;
}
