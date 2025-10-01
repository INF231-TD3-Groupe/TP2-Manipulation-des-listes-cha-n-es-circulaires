#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* create(int x) {
    Node* n = malloc(sizeof(Node));
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}

void insertSorted(Node **head, int x) {
    Node* n = create(x);
    if (!*head || (*head)->data >= x) {
        n->next = *head;
        if (*head) (*head)->prev = n;
        *head = n;
        return;
    }
    Node* temp = *head;
    while (temp->next && temp->next->data < x)
        temp = temp->next;
    n->next = temp->next;
    if (temp->next) temp->next->prev = n;
    temp->next = n;
    n->prev = temp;
}

void print(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertSorted(&head, 5);
    insertSorted(&head, 2);
    insertSorted(&head, 8);
    insertSorted(&head, 3);
    print(head);
    return 0;
}