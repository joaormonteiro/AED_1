#include <stdlib.h>
#include "gerador_vetor.h"

void gerarVetorAleatorio(int vetor[], int tamanho, int limite) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % limite; // Gera números aleatórios de 0 a limite-1
    }
}
