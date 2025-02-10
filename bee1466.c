#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* insert_iterative(Node *root, int value) {
    Node **current = &root;
    while (*current != NULL) {
        if (value < (*current)->data) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }
    *current = (Node *)malloc(sizeof(Node));
    (*current)->data = value;
    (*current)->left = NULL;
    (*current)->right = NULL;
    return root;
}

void free_tree(Node *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    int C, case_num = 1;
    scanf("%d", &C);
    while (C--) {
        int N;
        scanf("%d", &N);
        Node *root = NULL;
        for (int i = 0; i < N; ++i) {
            int num;
            scanf("%d", &num);
            root = insert_iterative(root, num);
        }
        int *result = (int *)malloc(N * sizeof(int));
        int index = 0;
        Node *queue[1000];
        int front = 0, rear = 0;
        if (root != NULL) {
            queue[rear++] = root;
            while (front < rear) {
                Node *current = queue[front++];
                result[index++] = current->data;
                if (current->left != NULL) {
                    queue[rear++] = current->left;
                }
                if (current->right != NULL) {
                    queue[rear++] = current->right;
                }
            }
        }
        printf("Case %d:\n", case_num++);
        for (int i = 0; i < index; ++i) {
            if (i > 0) printf(" ");
            printf("%d", result[i]);
        }
        printf("\n\n");
        free(result);
        free_tree(root);
    }
    return 0;
}