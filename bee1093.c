#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 100

typedef struct {
    int ev1;
    int index;
} State;

State states[MAX_STATES];
int state_count;

int visited[200000]; // Aumentado para suportar valores maiores de ev1
int S, D;
double p;

void collect_states(int initial_ev1) {
    int queue[MAX_STATES];
    int front = 0, rear = 0;
    state_count = 0;
    memset(visited, 0, sizeof(visited));

    queue[rear++] = initial_ev1;
    visited[initial_ev1] = 1;

    while (front < rear && rear < MAX_STATES) {
        int ev1 = queue[front++];
        states[state_count].ev1 = ev1;
        states[state_count].index = state_count;
        state_count++;

        int next_win = ev1 + D;
        if (next_win > 0 && next_win < S && !visited[next_win]) {
            visited[next_win] = 1;
            queue[rear++] = next_win;
        }

        int next_lose = ev1 - D;
        if (next_lose > 0 && next_lose < S && !visited[next_lose]) {
            visited[next_lose] = 1;
            queue[rear++] = next_lose;
        }
    }
}

int get_state_index(int ev1) {
    for (int i = 0; i < state_count; i++) {
        if (states[i].ev1 == ev1) {
            return i;
        }
    }
    return -1;
}

void build_system(double A[MAX_STATES][MAX_STATES], double B[MAX_STATES]) {
    for (int i = 0; i < state_count; i++) {
        int ev1 = states[i].ev1;

        for (int j = 0; j < state_count; j++) {
            A[i][j] = 0.0;
        }
        B[i] = 0.0;

        A[i][i] = 1.0;

        // Processar next_win
        int next_win = ev1 + D;
        if (next_win >= S) {
            B[i] += p * 1.0;
        } else if (next_win <= 0) {
            B[i] += p * 0.0;
        } else {
            int idx = get_state_index(next_win);
            if (idx != -1) {
                A[i][idx] -= p;
            }
        }

        // Processar next_lose
        int next_lose = ev1 - D;
        if (next_lose >= S) {
            B[i] += (1 - p) * 1.0;
        } else if (next_lose <= 0) {
            B[i] += (1 - p) * 0.0;
        } else {
            int idx = get_state_index(next_lose);
            if (idx != -1) {
                A[i][idx] -= (1 - p);
            }
        }
    }
}

void gaussian_elimination(int n, double A[MAX_STATES][MAX_STATES], double B[MAX_STATES]) {
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i; j < n; j++) {
            if (A[j][i] != 0) {
                pivot = j;
                break;
            }
        }
        if (pivot != i) {
            for (int j = 0; j < n; j++) {
                double temp = A[i][j];
                A[i][j] = A[pivot][j];
                A[pivot][j] = temp;
            }
            double temp = B[i];
            B[i] = B[pivot];
            B[pivot] = temp;
        }

        double factor = A[i][i];
        if (factor == 0) continue;

        for (int j = i; j < n; j++) {
            A[i][j] /= factor;
        }
        B[i] /= factor;

        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            double factor = A[k][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            B[k] -= factor * B[i];
        }
    }
}

int main() {
    int EV1, EV2, AT, D_input;
    while (1) {
        scanf("%d %d %d %d", &EV1, &EV2, &AT, &D_input);
        if (EV1 == 0 && EV2 == 0 && AT == 0 && D_input == 0) break;

        S = EV1 + EV2;
        if (EV1 <= 0) {
            printf("0.0\n");
            continue;
        }
        if (EV2 <= 0) {
            printf("100.0\n");
            continue;
        }

        D = D_input;
        p = (double)AT / 6.0;

        collect_states(EV1);

        if (state_count == 0) {
            printf("0.0\n");
            continue;
        }

        double A[MAX_STATES][MAX_STATES];
        double B[MAX_STATES];
        build_system(A, B);

        gaussian_elimination(state_count, A, B);

        int initial_index = get_state_index(EV1);
        if (initial_index == -1) {
            printf("0.0\n");
        } else {
            double probability = B[initial_index] * 100;
            printf("%.1f\n", probability);
        }
    }

    return 0;
}