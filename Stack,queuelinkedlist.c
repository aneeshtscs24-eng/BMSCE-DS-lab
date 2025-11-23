#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Display Linked List
void display() {
    struct Node* temp = head;
    if (head == NULL) {
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

// ******** STACK OPERATIONS ********

// PUSH: Insert at beginning (Stack)
void push(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("%d pushed to stack.\n", value);
}

// POP: Remove from beginning (Stack)
void pop() {
    if (head == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = head;
    printf("%d popped from stack.\n", temp->data);
    head = head->next;
    free(temp);
}


// ******** QUEUE OPERATIONS ********

// ENQUEUE: Insert at end (Queue)
void enqueue(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        printf("%d enqueued.\n", value);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("%d enqueued.\n", value);
}

// DEQUEUE: Remove from beginning (Queue)
void dequeue() {
    if (head == NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node* temp = head;
    printf("%d dequeued.\n", temp->data);
    head = head->next;
    free(temp);
}


// ******** MAIN MENU ********

int main() {
    int choice, value;

    while (1) {
        printf("\n--- SINGLE LINKED LIST STACK & QUEUE SIMULATION ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Enqueue (Queue)\n");
        printf("4. Dequeue (Queue)\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to PUSH: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Enter value to ENQUEUE: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 4:
                dequeue();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
