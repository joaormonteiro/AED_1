#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char caractere;
    struct Node *prox;
} Node;

Node *criaNo(char caractere)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->caractere = caractere;
    novo->prox = NULL;
    return novo;
}

Node *insereNo(Node *cabeca, char caractere)
{
    Node *novo = criaNo(caractere);
    if (cabeca == NULL)
    {
        return novo;
    }
    Node *atual = cabeca;
    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }
    atual->prox = novo;
    return cabeca;
}

void limpaLista(Node *cabeca)
{
    Node *atual = cabeca;
    while (atual != NULL)
    {
        Node *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int contarDiamantes(Node *cabeca)
{
    int diamantes = 0;
    while (1)
    {
        Node *atual = cabeca;
        Node *prev = NULL;
        int achouDiamante = 0;

        // Procurar por pares de diamantes '<' '>'
        while (atual != NULL && atual->prox != NULL)
        {
            if (atual->caractere == '<' && atual->prox->caractere == '>')
            {
                diamantes++; // Encontrou um diamante

                // Remover o diamante da lista
                if (prev == NULL)
                {
                    cabeca = atual->prox->prox; // Atualiza a cabeça da lista
                    free(atual);
                    free(atual->prox);
                    atual = cabeca;
                }
                else
                {
                    prev->prox = atual->prox->prox; // Atualiza o nó anterior
                    free(atual);
                    free(atual->prox);
                    atual = prev->prox; // Avança para o próximo nó
                }
                achouDiamante = 1;
                break;
            }
            prev = atual;
            atual = atual->prox;
        }

        // Se não achou mais diamantes, sai do loop
        if (!achouDiamante)
        {
            break;
        }
    }
    return diamantes;
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar(); // Para consumir o '\n' após o número de casos

    for (int i = 0; i < n; i++)
    {
        char entrada[1001];
        fgets(entrada, 1001, stdin);

        Node *lista = NULL;

        // Constrói a lista a partir da entrada
        for (int j = 0; entrada[j] != '\0' && entrada[j] != '\n'; j++)
        {
            lista = insereNo(lista, entrada[j]);
        }

        int diamantes = contarDiamantes(lista);
        printf("%d\n", diamantes); // Imprime o número de diamantes encontrados

        limpaLista(lista); // Limpa a lista alocada
    }

    return 0;
}
