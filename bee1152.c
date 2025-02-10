#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int cmp(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int find(int *parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]); // Path compression
    return parent[x];
}

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
    int m, n;
    
    while (scanf("%d %d", &m, &n) && (m || n)) {
        Edge edges[n];
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            totalCost += edges[i].w;
        }

        // Ordena as arestas pelo peso
        qsort(edges, n, sizeof(Edge), cmp);

        int parent[m], rank[m];
        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int mstCost = 0, edgesUsed = 0;
        for (int i = 0; i < n && edgesUsed < m - 1; i++) {
            if (find(parent, edges[i].u) != find(parent, edges[i].v)) {
                union_sets(parent, rank, edges[i].u, edges[i].v);
                mstCost += edges[i].w;
                edgesUsed++;
            }
        }

        printf("%d\n", totalCost - mstCost);
    }
    
    return 0;
}
