/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Problema    : Maratona de Programação IME-USP - Sudoku 1383
Data        : 20/08/2026
Objetivo    : Verificar se uma matriz 9x9 preenchida é solução válida de
Sudoku (cada linha, coluna e quadrante 3x3 deve conter os números de 1 a 9).
Dificuldade : Sem dificuldades significativas — a lógica de checagem de linhas,
colunas e quadrantes 3x3 foi direta de implementar.
Uso de IA   : Usei o Claude Code para revisar o código e apontar possíveis
bugs antes da entrega.
-------------------------------------------------------------------------- */

#include <stdio.h>

void sudoku(int n, int sdk[n][9][9]) {
    // Ler o Sudoku
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                scanf("%d", &sdk[i][j][k]);
            }
        }
    }
}

void zerarvisto(int v[]) {
    // Zera o vetor que verifica se houve repetiçao de algum número
    for (int j = 0; j < 10; j++) {
        v[j] = 0;
    }
}

int verif(int v[][9][9], int n) {
    for (int i = 0; i < n; i++) {
        int valido = 1;
        int visto[10] = {
            0};  // Vetor que verifica se houve repetiçao de algum número
        // Verifica se todas as colunas estão válidas
        for (int j = 0; j < 9; j++) {
            zerarvisto(visto);
            for (int k = 0; k < 9; k++) {
                if (v[i][j][k] < 1 || v[i][j][k] > 9 ||
                    visto[v[i][j][k]] == 1) {
                    valido = 0;
                    break;
                } else {
                    visto[v[i][j][k]] = 1;
                }
            }
        }
        zerarvisto(visto);
        // Verificas e todas as linhas estão válidas

        for (int k = 0; k < 9; k++) {
            zerarvisto(visto);
            for (int j = 0; j < 9; j++) {
                if (v[i][j][k] < 1 || v[i][j][k] > 9 ||
                    visto[v[i][j][k]] == 1) {
                    valido = 0;
                    break;
                } else {
                    visto[v[i][j][k]] = 1;
                }
            }
        }
        zerarvisto(visto);

        // Verifica se todos os quadrantes estão válidos
        for (int l = 0; l < 9; l += 3) {
            for (int m = 0; m < 9; m += 3) {
                zerarvisto(visto);
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (v[i][l + j][m + k] < 1 || v[i][l + j][m + k] > 9 ||
                            visto[v[i][l + j][m + k]] == 1) {
                            valido = 0;
                            break;
                        } else {
                            visto[v[i][l + j][m + k]] = 1;
                        }
                    }
                }
            }
        }
        zerarvisto(visto);

        printf("Instancia %d\n", i + 1);
        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int sdk[n][9][9];
    sudoku(n, sdk);

    verif(sdk, n);
}