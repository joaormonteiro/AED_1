
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000

typedef struct Node {
    char c;
    struct Node *next;
} Node;

void print_list(Node *head) {
    Node *current = head;
    while (current) {
        putchar(current->c);
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    putchar('\n');
}

int main() {
    char input[MAX + 1];
    while (fgets(input, sizeof(input), stdin)) {
        Node *head = NULL, *tail = NULL, *current = NULL;
        for (int i = 0; input[i] != '\n' && input[i] != '\0'; i++) {
            if (input[i] == '[') {
                current = NULL;
            } else if (input[i] == ']') {
                current = tail;
            } else {
                Node *new_node = (Node *)malloc(sizeof(Node));
                new_node->c = input[i];
                new_node->next = NULL;
                if (!head) {
                    head = tail = new_node;
                } else if (!current) {
                    new_node->next = head;
                    head = new_node;
                } else {
                    new_node->next = current->next;
                    current->next = new_node;
                    if (!new_node->next) {
                        tail = new_node;
                    }
                }
                current = new_node;
            }
        }
        print_list(head);
    }
    return 0;
}
