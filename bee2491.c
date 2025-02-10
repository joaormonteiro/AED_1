#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    char grid[M][N+1];  // +1 para o caractere nulo
    
    for (int i = 0; i < M; i++) {
        scanf("%s", grid[i]);
    }
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int costa = 0;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '#') {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni < 0 || ni >= M || nj < 0 || nj >= N) {
                        costa++;
                        break;
                    } else if (grid[ni][nj] == '.') {
                        costa++;
                        break;
                    }
                }
            }
        }
    }
    
    printf("%d\n", costa);
    return 0;
}