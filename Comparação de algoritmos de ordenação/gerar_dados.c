#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador_vetor.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

#define REPETICOES 3

void gerar_dados() {
    FILE *arquivo = fopen("dados.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de dados.\n");
        return;
    }

    fprintf(arquivo, "Tamanho,InsertionSort,MergeSort,QuickSort\n");

    for (int tamanho = 20000; tamanho <= 400000; tamanho += 20000) {
        double tempo_insertion = 0.0, tempo_merge = 0.0, tempo_quick = 0.0;

        for (int i = 0; i < REPETICOES; i++) {
            int *vetor = (int *)malloc(tamanho * sizeof(int));
            int *copia_insertion = (int *)malloc(tamanho * sizeof(int));
            int *copia_merge = (int *)malloc(tamanho * sizeof(int));
            int *copia_quick = (int *)malloc(tamanho * sizeof(int));

            gerarVetorAleatorio(vetor, tamanho, 1000000);

            for (int j = 0; j < tamanho; j++) {
                copia_insertion[j] = copia_merge[j] = copia_quick[j] = vetor[j];
            }

            // InsertionSort
            clock_t inicio = clock();
            insertionSort(copia_insertion, tamanho);
            clock_t fim = clock();
            tempo_insertion += (double)(fim - inicio) / CLOCKS_PER_SEC;

            // MergeSort
            inicio = clock();
            mergeSort(copia_merge, 0, tamanho - 1);
            fim = clock();
            tempo_merge += (double)(fim - inicio) / CLOCKS_PER_SEC;

            // QuickSort
            inicio = clock();
            quickSort(copia_quick, 0, tamanho - 1);
            fim = clock();
            tempo_quick += (double)(fim - inicio) / CLOCKS_PER_SEC;

            free(vetor);
            free(copia_insertion);
            free(copia_merge);
            free(copia_quick);
        }

        fprintf(arquivo, "%d,%.6f,%.6f,%.6f\n", tamanho, tempo_insertion / REPETICOES, tempo_merge / REPETICOES, tempo_quick / REPETICOES);
        printf("Tamanho %d processado.\n", tamanho);
    }

    fclose(arquivo);
    printf("Dados salvos em dados.csv.\n");
}
