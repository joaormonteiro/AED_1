#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_M 1000 // Máximo de palavras no dicionário
#define MAX_LEN 17 // Máximo de caracteres em uma palavra (16 + '\0')

typedef struct
{
    char palavra[MAX_LEN];
    int valor;
} HayPoint;

HayPoint hay_points[MAX_M]; // Array para armazenar as palavras e valores
int total_palavras = 0;

// Função para buscar o valor da palavra no dicionário
int buscar_valor(char *palavra)
{
    for (int i = 0; i < total_palavras; i++)
    {
        if (strcmp(hay_points[i].palavra, palavra) == 0)
        {
            return hay_points[i].valor;
        }
    }
    return 0; // Se não encontrar, retorna 0
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);

    // Lendo o dicionário de palavras
    for (int i = 0; i < M; i++)
    {
        scanf("%s %d", hay_points[i].palavra, &hay_points[i].valor);
    }
    total_palavras = M;

    // Processando descrições
    char palavra[MAX_LEN];
    int salario = 0;

    while (N > 0)
    {
        while (scanf("%s", palavra) == 1)
        {
            if (strcmp(palavra, ".") == 0)
            {
                printf("%d\n", salario); // Imprime o salário da descrição
                salario = 0;             // Reinicia para a próxima descrição
                N--;                     // Reduz o número de descrições restantes
                break;
            }
            salario += buscar_valor(palavra); // Soma o valor das palavras encontradas
        }
    }

    return 0;
}
