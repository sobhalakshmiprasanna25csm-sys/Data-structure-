
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to insert a node at a given position
void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    // Insert at the beginning
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d.\n", value, pos);
        return;
    }

    // Traverse to the node before the required position
    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // Check whether the position is valid
    if (temp == NULL) {
        printf("Position %d is out of range.\n", pos);
        free(newNode);
        return;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", value, pos);
}

// Function to display the linked list
void display() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Position\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &pos);

                insertAtPosition(value, pos);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
