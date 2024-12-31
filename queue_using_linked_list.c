/*queue using linked list in c: 
1. Write a program to insert an element into the
queue using linked list (Insert Operation).
2. Write a program to delete an element from the
queue using linked list (Delete Operation).
3. Write a program to return the value of the front
element of the queue (without deleting it from the
queue) using linked list (Peep operation).
4. Write a program to display the elements of a
queue using linked list .*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;  // Initialize front of the queue
Node* rear = NULL;   // Initialize rear of the queue

// Function to insert an element into the queue (Insert operation)
void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed! Cannot insert %d.\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        // If the queue is empty, both front and rear are the new node
        front = rear = newNode;
    } else {
        // Add the new node at the end of the queue and update rear
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into the queue.\n", value);
}

// Function to delete an element from the queue (Delete operation)
void delete() {
    if (front == NULL) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }

    Node* temp = front;
    printf("%d deleted from the queue.\n", front->data);
    front = front->next;
    
    // If the queue becomes empty, set rear to NULL
    if (front == NULL) {
        rear = NULL;
    }
    
    free(temp); // Free the memory of the deleted node
}

// Function to return the front element of the queue (Peep operation)
void peep() {
    if (front == NULL) {
        printf("The queue is empty. No front element.\n");
    } else {
        printf("The front element is %d.\n", front->data);
    }
}

// Function to display all elements of the queue
void display() {
    if (front == NULL) {
        printf("The queue is empty.\n");
    } else {
        Node* temp = front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peep (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                peep();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
