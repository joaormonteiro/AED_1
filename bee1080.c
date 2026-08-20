/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 20/08/2026
Objetivo    : Ler 100 valores inteiros e apresentar o maior valor lido e sua
posição. Dificuldade : Evitar erros de índice ao percorrer o vetor e ao
converter entre posição 0-indexada (armazenamento) e 1-indexada (saída
esperada). Uso de IA   : Usei o Claude Code para revisar o código e apontar
bugs: uso indevido do operador vírgula em "return", acesso fora dos limites do
vetor no loop, e erro de indexação ao recuperar o maior valor a partir da
posição salva.
-------------------------------------------------------------------------- */

#include <stdio.h>

int PosicaoValor(int i[], int tamanho) {
    int MaiorValor = 0;
    int PosicaoMaiorValor = 0;
    for (int j = 0; j < tamanho; j++) {
        if (i[j] > MaiorValor) {
            MaiorValor = i[j];
            PosicaoMaiorValor = j + 1;
        }
    }
    return PosicaoMaiorValor;
}

int main() {
    int tamanho = 100;
    int inteiros[tamanho];
    for (int i = 0; i < tamanho; i++) {
        scanf("%d ", &inteiros[i]);
    }

    int posicao = PosicaoValor(inteiros, tamanho);
    printf("%d\n", inteiros[posicao - 1]);
    printf("%d\n", posicao);
}
