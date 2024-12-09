#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador_vetor.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

int main(void) {
    int tamanho;

    // Solicitar o tamanho do vetor ao usuário
    printf("Digite o tamanho do vetor a ser ordenado: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido. O programa será encerrado.\n");
        return 1;
    }

    // Gerar vetor original
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    gerarVetorAleatorio(vetor, tamanho, tamanho * 2);

    // Criar cópias do vetor
    int *vetor_insertion = (int *)malloc(tamanho * sizeof(int));
    int *vetor_merge = (int *)malloc(tamanho * sizeof(int));
    int *vetor_quick = (int *)malloc(tamanho * sizeof(int));

    if (vetor_insertion == NULL || vetor_merge == NULL || vetor_quick == NULL) {
        printf("Erro ao alocar memória.\n");
        free(vetor);
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        vetor_insertion[i] = vetor[i];
        vetor_merge[i] = vetor[i];
        vetor_quick[i] = vetor[i];
    }

    // Medir tempo do InsertionSort
    clock_t inicio = clock();
    insertionSort(vetor_insertion, tamanho);
    clock_t fim = clock();
    double tempo_insertion = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Medir tempo do MergeSort
    inicio = clock();
    mergeSort(vetor_merge, 0, tamanho - 1);
    fim = clock();
    double tempo_merge = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Medir tempo do QuickSort
    inicio = clock();
    quickSort(vetor_quick, 0, tamanho - 1);
    fim = clock();
    double tempo_quick = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Exibir resultados
    printf("Tempo do InsertionSort: %.6f segundos\n", tempo_insertion);
    printf("Tempo do MergeSort: %.6f segundos\n", tempo_merge);
    printf("Tempo do QuickSort: %.6f segundos\n", tempo_quick);

    // Liberar memória
    free(vetor);
    free(vetor_insertion);
    free(vetor_merge);
    free(vetor_quick);

    return 0;
}
