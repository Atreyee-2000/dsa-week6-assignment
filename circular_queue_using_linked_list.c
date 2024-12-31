/*circular queue using linked list in c 
1. Write a program to insert an element into the
circular queue.
2. Write a program to delete an element from a
circular queue.
3. Write a program to return the value of the FRONT
element of the circular queue(without deleting it
from the queue).
4. Write a program to display the elements of a
circular queue.*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node in the circular queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;  // Front of the queue
Node* rear = NULL;   // Rear of the queue

// Function to check if the circular queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to insert an element into the circular queue
void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed! Cannot insert %d.\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        // If the queue is empty, both front and rear are the new node
        front = rear = newNode;
        rear->next = front; // Point rear's next to front to complete the circular link
    } else {
        // Add the new node at the rear and update rear
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Keep the circular link intact
    }
    printf("%d inserted into the circular queue.\n", value);
}

// Function to delete an element from the circular queue
void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }

    Node* temp = front;
    printf("%d deleted from the circular queue.\n", front->data);

    if (front == rear) {
        // If there's only one element in the queue
        free(temp);
        front = rear = NULL;
    } else {
        // Move front to the next element
        front = front->next;
        rear->next = front; // Maintain circular link
        free(temp); // Free the memory of the deleted node
    }
}

// Function to return the front element of the circular queue (Peep operation)
void peep() {
    if (isEmpty()) {
        printf("The queue is empty. No front element.\n");
    } else {
        printf("The front element is %d.\n", front->data);
    }
}

// Function to display all elements in the circular queue
void display() {
    if (isEmpty()) {
        printf("The queue is empty.\n");
    } else {
        Node* temp = front;
        printf("Circular Queue elements: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peep (Front Element)\n");
        printf("4. Display Circular Queue\n");
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

