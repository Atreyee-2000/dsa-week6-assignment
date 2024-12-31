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

#define MAX 5 // Size of the circular queue

int queue[MAX];
int front = -1, rear = -1;  // Initializing front and rear pointers

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element into the circular queue
void insert(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;  // Set front and rear to 0 when inserting into an empty queue
    } else {
        rear = (rear + 1) % MAX;  // Circular increment for rear
    }
    queue[rear] = value;
    printf("%d inserted into the circular queue.\n", value);
}

// Function to delete an element from the circular queue
void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }
    printf("%d deleted from the circular queue.\n", queue[front]);
    if (front == rear) {
        // If the queue becomes empty after deletion
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;  // Circular increment for front
    }
}

// Function to return the front element of the circular queue (Peep operation)
void peep() {
    if (isEmpty()) {
        printf("The queue is empty. No front element.\n");
    } else {
        printf("The front element is %d.\n", queue[front]);
    }
}

// Function to display all elements in the circular queue
void display() {
    if (isEmpty()) {
        printf("The queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;  // Circular increment
        }
        printf("%d\n", queue[rear]); // Print the last element
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
