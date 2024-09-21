#include <stdio.h>
#include <stdlib.h>

struct Node {
    int col;
    int val;
    struct Node* next;
};

void createSparse(int a[][3], int rows, int cols) {
    struct Node* A[rows];
    struct Node* temp;
    struct Node* p;
    
    for (int i = 0; i < rows; i++) {
        A[i] = NULL;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] != 0) {
               
                struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
                new_node->val = a[i][j];
                new_node->col = j;
                new_node->next = NULL;

                if (A[i] == NULL) {
                    A[i] = new_node;
                } else {
                    temp = A[i];
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = new_node;
                }
            }
        }
    }

    printf("Sparse Matrix:\n");
    for (int i = 0; i < rows; i++) {
        p = A[i];
        for (int j = 0; j < cols; j++) {
            if (p != NULL && j == p->col) {
                printf("%d\t", p->val);
                p = p->next;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main() {
    int a[3][3] = {{0, 0, 2},
                   {0, 1, 0},
                   {5, 0, 4}};

    createSparse(a, 3, 3);

    return 0;
}
