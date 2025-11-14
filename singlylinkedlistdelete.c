#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end (to create linked list easily)
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete first element
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted first element: %d\n", temp->data);
    free(temp);
}

// Delete last element
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == NULL) {
        printf("Deleted last element: %d\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted last element: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Delete specified element (by value)
void deleteElement(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        printf("Deleted element: %d\n", key);
        free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found!\n", key);
        return;
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n", key);
    free(temp);
}

// Display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Create linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    displayList(head);

    // Deletion operations
    deleteFirst(&head);
    displayList(head);

    deleteLast(&head);
    displayList(head);

    deleteElement(&head, 20);
    displayList(head);

    deleteElement(&head, 100); // Not found case

    return 0;
}