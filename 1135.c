#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 100005

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge* edges;
    int size;
    int capacity;
} AdjList;

AdjList adj[MAXN];
int depth[MAXN];
long long dist[MAXN];
int** parent;
int LOG;

// Função para inicializar uma lista de adjacência
void init_adj_list(int n) {
    for (int i = 0; i < n; i++) {
        adj[i].edges = NULL;
        adj[i].size = 0;
        adj[i].capacity = 0;
    }
}

// Adiciona uma aresta na lista de adjacência
void add_edge(int u, int v, int w) {
    if (adj[u].size == adj[u].capacity) {
        adj[u].capacity = adj[u].capacity ? adj[u].capacity * 2 : 4;
        adj[u].edges = realloc(adj[u].edges, adj[u].capacity * sizeof(Edge));
    }
    adj[u].edges[adj[u].size++] = (Edge){v, w};
}

// DFS para calcular profundidade, distância e ancestrais imediatos
void dfs(int node, int par, long long d) {
    parent[node][0] = par;
    dist[node] = d;

    for (int i = 0; i < adj[node].size; i++) {
        Edge edge = adj[node].edges[i];
        if (edge.node != par) {
            depth[edge.node] = depth[node] + 1;
            dfs(edge.node, node, d + edge.weight);
        }
    }
}

// Preprocessamento para LCA com Binary Lifting
void preprocess(int n) {
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

// Calcula o LCA de dois nós
int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        int temp = u;
        u = v;
        v = temp;
    }

    for (int j = LOG - 1; j >= 0; j--) {
        if (parent[u][j] != -1 && depth[parent[u][j]] >= depth[v]) {
            u = parent[u][j];
        }
    }

    if (u == v) return u;

    for (int j = LOG - 1; j >= 0; j--) {
        if (parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0];
}

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        // Inicialização
        init_adj_list(n);
        memset(depth, 0, sizeof(depth));
        memset(dist, 0, sizeof(dist));

        // Calcula LOG dinamicamente
        LOG = ceil(log2(n)) + 1;

        // Alocação dinâmica para parent
        parent = malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) {
            parent[i] = malloc(LOG * sizeof(int));
            memset(parent[i], -1, LOG * sizeof(int));
        }

        // Leitura da árvore
        for (int i = 1; i < n; i++) {
            int a, l;
            scanf("%d %d", &a, &l);
            add_edge(i, a, l);
            add_edge(a, i, l);
        }

        // Pré-processamento
        dfs(0, -1, 0);
        preprocess(n);

        // Processamento de consultas
        int q;
        scanf("%d", &q);
        while (q--) {
            int s, t;
            scanf("%d %d", &s, &t);
            int l = lca(s, t);
            printf("%lld", dist[s] + dist[t] - 2 * dist[l]);
            if (q) printf(" ");
        }
        printf("\n");

        // Liberação de memória
        for (int i = 0; i < n; i++) {
            free(adj[i].edges);
            free(parent[i]);
        }
        free(parent);
    }

    return 0;
}
