#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 26

// Estrutura para o grafo
typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES]; // Matriz de adjacência
    int visited[MAX_VERTICES];          // Vértices visitados
    int vertices;                       // Número de vértices
} Graph;

// Inicializa o grafo
void initGraph(Graph *g, int vertices) {
    g->vertices = vertices;
    memset(g->adj, 0, sizeof(g->adj));
    memset(g->visited, 0, sizeof(g->visited));
}

// Adiciona uma aresta ao grafo
void addEdge(Graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

// Realiza a busca em profundidade
void dfs(Graph *g, int vertex, char *component) {
    g->visited[vertex] = 1;
    // Adiciona o vértice ao componente atual
    char currentVertex = 'a' + vertex;
    strncat(component, &currentVertex, 1);
    strcat(component, ",");

    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[vertex][i] && !g->visited[i]) {
            dfs(g, i, component);
        }
    }
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++) {
        int V, E;
        scanf("%d %d", &V, &E);

        Graph g;
        initGraph(&g, V);

        for (int i = 0; i < E; i++) {
            char u, v;
            scanf(" %c %c", &u, &v);
            addEdge(&g, u - 'a', v - 'a');
        }

        printf("Case #%d:\n", t);

        int connectedComponents = 0;

        for (int i = 0; i < V; i++) {
            if (!g.visited[i]) {
                char component[100] = "";
                dfs(&g, i, component);
                // Ordena os caracteres no componente
                int length = strlen(component);
                char nodes[MAX_VERTICES];
                int index = 0;
                for (int j = 0; j < length; j++) {
                    if (component[j] != ',') {
                        nodes[index++] = component[j];
                    }
                }
                nodes[index] = '\0';
                qsort(nodes, index, sizeof(char), (int (*)(const void *, const void *))strcmp);

                for (int j = 0; j < index; j++) {
                    printf("%c,", nodes[j]);
                }
                printf("\n");

                connectedComponents++;
            }
        }

        printf("%d connected components\n\n", connectedComponents);
    }

    return 0;
}