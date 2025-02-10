#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_M 10000

int dist[MAX_N][MAX_N];
int N, M;

void dijkstra(int source, int distancias[]) {
    bool visited[MAX_N] = {false};
    for (int i = 0; i < N; i++) {
        distancias[i] = INT_MAX;
    }
    distancias[source] = 0;
    
    for (int i = 0; i < N; i++) {
        int u = -1;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && (u == -1 || distancias[j] < distancias[u])) {
                u = j;
            }
        }
        visited[u] = true;
        
        for (int v = 0; v < N; v++) {
            if (dist[u][v] != INT_MAX && distancias[u] + dist[u][v] < distancias[v]) {
                distancias[v] = distancias[u] + dist[u][v];
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    // Inicializa a matriz de distâncias
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INT_MAX;
            }
        }
    }

    // Lê as estradas e preenche a matriz de distâncias
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Para cada cidade, calcula as distâncias mínimas de todas as outras
    int min_max_dist = INT_MAX;
    for (int i = 0; i < N; i++) {
        int distancias[MAX_N];
        dijkstra(i, distancias);

        // A maior distância de i até qualquer outra cidade
        int max_dist = 0;
        for (int j = 0; j < N; j++) {
            if (distancias[j] > max_dist) {
                max_dist = distancias[j];
            }
        }

        // Minimizando a maior distância
        if (max_dist < min_max_dist) {
            min_max_dist = max_dist;
        }
    }

    printf("%d\n", min_max_dist);
    return 0;
}
