#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insertBeginning(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;
    head->prev = newNode;
    last->next = newNode;

    head = newNode;
}

void insertPosition(int value, int pos) {
    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
