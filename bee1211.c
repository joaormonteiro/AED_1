#include <stdio.h>
#include <string.h>

#define MAX_N 100000
#define MAX_LEN 200

char telefones[MAX_N][MAX_LEN + 1];

int contar_prefixos(int n) {
    int economia = 0;
    for (int i = 1; i < n; i++) {
        int j = 0;
        while (telefones[i][j] && telefones[i][j] == telefones[i - 1][j]) {
            j++;
        }
        economia += j;
    }
    return economia;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s", telefones[i]);
        }
        
        // Ordenação lexicográfica dos números
        qsort(telefones, n, sizeof(telefones[0]), (int (*)(const void *, const void *)) strcmp);
        
        printf("%d\n", contar_prefixos(n));
    }
    return 0;
}
