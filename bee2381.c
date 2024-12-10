#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 30

typedef struct No
{
    char nome[MAX_NOME];
    struct No *proximo;
} No;

void inserir(No **cabeca, char nome[MAX_NOME])
{
    No *novo_no = (No *)malloc(sizeof(No));
    strcpy(novo_no->nome, nome);
    novo_no->proximo = NULL;

    if (*cabeca == NULL)
    {
        *cabeca = novo_no;
    }
    else
    {
        No *atual = *cabeca;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
}

void acessar_aluno(No *cabeca, int k)
{
    int count = 1;
    No *atual = cabeca;

    while (atual != NULL)
    {
        if (count == k)
        {
            printf("%s\n", atual->nome);
            return;
        }
        count++;
        atual = atual->proximo;
    }
}

void ordenar(No *cabeca)
{
    if (cabeca == NULL)
        return;

    int trocado;
    No *atual;
    No *ultimo = NULL;

    do
    {
        trocado = 0;
        atual = cabeca;

        while (atual->proximo != ultimo)
        {
            if (strcmp(atual->nome, atual->proximo->nome) > 0)
            {
                char temp[MAX_NOME];
                strcpy(temp, atual->nome);
                strcpy(atual->nome, atual->proximo->nome);
                strcpy(atual->proximo->nome, temp);

                trocado = 1;
            }
            atual = atual->proximo;
        }

    } while (trocado);
}

int main(void) {
    int n, k;

    No*cabeca = NULL;

    scanf("%d %d", &n, &k);

    for (int i = 0 ; i < n; i++)
    {
        char nome[MAX_NOME];
        scanf("%s", nome);
        inserir(&cabeca, nome);
    }
    
    ordenar(cabeca);

    acessar_aluno(cabeca, k);

    return 0;

}