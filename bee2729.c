#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct item
{
  char name[21];
  struct item *next;
};

struct item *add_new_item(char name[21])
{
  struct item *new_item = malloc(sizeof(struct item));
  strncpy(new_item->name, name, 20);
  new_item->next = NULL;
  return new_item;
}

struct item *find_last_item(struct item *head)
{
  struct item *last_item = head;
  while (last_item->next != NULL)
  {
    last_item = last_item->next;
  }
  return last_item;
}

void remove_item(struct item *head, struct item *trash)
{
  struct item *item_that_points_to_trash = head;
  while (item_that_points_to_trash->next != trash)
  {
    item_that_points_to_trash = item_that_points_to_trash->next;
  }
  item_that_points_to_trash->next = trash->next;
  free(trash);
}

void remove_list(struct item *head)
{
  struct item *current = head->next;
  while (current != NULL)
  {
    struct item *temp = current;
    current = current->next;
    free(temp);
  }
  head->next = NULL;
}

void print_items(struct item *head)
{
  struct item *current_item = head->next;
  bool isFirst = true;
  while (current_item != NULL)
  {
    if (!isFirst)
      printf(" ");
    printf("%s", current_item->name);
    isFirst = false;
    current_item = current_item->next;
  }
  printf("\n");
}

bool check_if_is_unique(struct item *head, char name[21])
{
  struct item *current = head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
      return false;
    current = current->next;
  }
  return true;
}

void sort_list(struct item *head)
{
  if (head == NULL || head->next == NULL)
    return;

  bool sorted = false;
  while (!sorted)
  {
    sorted = true;
    struct item *prev = head;
    struct item *current = head->next;

    while (current != NULL && current->next != NULL)
    {
      if (strcmp(current->name, current->next->name) > 0)
      {
        // Swap current and next
        struct item *a = current->next;
        current->next = a->next;
        a->next = current;
        prev->next = a;

        sorted = false;

        prev = a;
      }
      else
      {
        prev = current;
        current = current->next;
      }
    }
  }
}

int main()
{
  int n;

  struct item head;
  strcpy(head.name, "Head");
  head.next = NULL;
  struct item *pHead = &head;

  do
  {
    scanf("%d", &n);
  } while (n <= 0 || n > 100);

  getchar();
  for (int i = 0; i < n; i++)
  {
    char line_text[21000] = {0};
    fgets(line_text, sizeof(line_text) - 1, stdin);
    int line_text_size = strlen(line_text);
    int word_count = 0;
    remove_list(pHead);

    for (int j = 0; j < line_text_size; j++)
    {
      if (line_text[j] == ' ' || line_text[j] == '\0' || line_text[j] == '\n')
      {
        if (word_count > 0)
        {
          char word[21] = {0};
          for (int z = 0; z < word_count; z++)
          {
            word[z] = line_text[j - word_count + z];
          }
          word[word_count] = '\0';
          if (check_if_is_unique(pHead, word) == true)
          {
            struct item *new_item = add_new_item(word);
            struct item *last_item = find_last_item(pHead);
            last_item->next = new_item;
          }
          word_count = 0;
        }
      }
      else
      {
        word_count++;
      }
    }
    sort_list(pHead);
    print_items(pHead);
  }

  return 0;
}