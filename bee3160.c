#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
  char nome[50];
  struct Node *prox;
} Node;

Node *criaNo(char *nome)
{
  Node *novoNo = (Node *)malloc(sizeof(Node));
  strcpy(novoNo->nome, nome);
  novoNo->prox = NULL;
  return novoNo;
}

void adicionaNoFinal(Node **head, char *nome)
{
  Node *novoNo = criaNo(nome);
  if (*head == NULL)
  {
    *head = novoNo;
  }
  else
  {
    Node *temp = *head;
    while (temp->prox != NULL)
    {
      temp = temp->prox;
    }
    temp->prox = novoNo;
  }
}

void imprimeLista(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    printf("%s", temp->nome);
    if (temp->prox != NULL)
    {
      printf(" ");
    }
    temp = temp->prox;
  }
  printf("\n");
}

void liberaLista(Node *head)
{
  Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->prox;
    free(temp);
  }
}

int main()
{
  char amigosL[1000], amigosN[1000], amigoS[50];
  Node *listaAmigosL = NULL, *listaAmigosN = NULL;

  fgets(amigosL, sizeof(amigosL), stdin);
  amigosL[strcspn(amigosL, "\n")] = '\0';

  fgets(amigosN, sizeof(amigosN), stdin);
  amigosN[strcspn(amigosN, "\n")] = '\0';

  fgets(amigoS, sizeof(amigoS), stdin);
  amigoS[strcspn(amigoS, "\n")] = '\0';

  char *token = strtok(amigosL, " ");
  while (token != NULL)
  {
    adicionaNoFinal(&listaAmigosL, token);
    token = strtok(NULL, " ");
  }

  token = strtok(amigosN, " ");
  while (token != NULL)
  {
    adicionaNoFinal(&listaAmigosN, token);
    token = strtok(NULL, " ");
  }

  Node *temp = listaAmigosL;
  Node *anterior = NULL;
  int inseriu = 0;

  if (strcmp(amigoS, "nao") != 0)
  {
    while (temp != NULL)
    {
      if (strcmp(temp->nome, amigoS) == 0)
      {
        if (anterior == NULL)
        {
          Node *fimListaN = listaAmigosN;
          while (fimListaN->prox != NULL)
          {
            fimListaN = fimListaN->prox;
          }
          fimListaN->prox = listaAmigosL;
          listaAmigosL = listaAmigosN;
        }
        else
        {
          anterior->prox = listaAmigosN;
          Node *fimListaN = listaAmigosN;
          while (fimListaN->prox != NULL)
          {
            fimListaN = fimListaN->prox;
          }
          fimListaN->prox = temp;
        }
        inseriu = 1;
        break;
      }
      anterior = temp;
      temp = temp->prox;
    }
  }

  if (!inseriu)
  {
    Node *fimListaL = listaAmigosL;
    if (fimListaL == NULL)
    {
      listaAmigosL = listaAmigosN;
    }
    else
    {
      while (fimListaL->prox != NULL)
      {
        fimListaL = fimListaL->prox;
      }
      fimListaL->prox = listaAmigosN;
    }
  }

  imprimeLista(listaAmigosL);
  liberaLista(listaAmigosL);

  return 0;
}
