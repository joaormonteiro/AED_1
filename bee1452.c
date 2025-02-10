#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

typedef struct {
    char **apps;
    int count;
} Server;

typedef struct {
    char **apps;
    int count;
} Client;

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N, M;
    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;

        Server *servers = malloc(N * sizeof(Server));
        for (int i = 0; i < N; i++) {
            int qi;
            scanf("%d", &qi);
            servers[i].count = qi;
            servers[i].apps = malloc(qi * sizeof(char *));
            for (int j = 0; j < qi; j++) {
                char app[21];
                scanf("%s", app);
                servers[i].apps[j] = strdup(app);
            }
            qsort(servers[i].apps, qi, sizeof(char *), compare);
        }

        Client *clients = malloc(M * sizeof(Client));
        for (int i = 0; i < M; i++) {
            int pj;
            scanf("%d", &pj);
            clients[i].count = pj;
            clients[i].apps = malloc(pj * sizeof(char *));
            for (int j = 0; j < pj; j++) {
                char app[21];
                scanf("%s", app);
                clients[i].apps[j] = strdup(app);
            }
            qsort(clients[i].apps, pj, sizeof(char *), compare);
        }

        int total = 0;
        for (int c = 0; c < M; c++) {
            Client *client = &clients[c];
            for (int s = 0; s < N; s++) {
                Server *server = &servers[s];
                int found = 0;
                for (int a = 0; a < client->count; a++) {
                    char *key = client->apps[a];
                    if (bsearch(&key, server->apps, server->count, sizeof(char *), compare)) {
                        found = 1;
                        break;
                    }
                }
                if (found) total++;
            }
        }

        printf("%d\n", total);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < servers[i].count; j++)
                free(servers[i].apps[j]);
            free(servers[i].apps);
        }
        free(servers);

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < clients[i].count; j++)
                free(clients[i].apps[j]);
            free(clients[i].apps);
        }
        free(clients);
    }
    return 0;
}