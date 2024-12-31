/*queue using array in c 
1. Write a program to insert an element into the
queue using an array (Enqueue Operation).
2. Write a program to delete an element from the
queue using an array (Dequeue Operation).
3. Write a program to return the value of the FRONT
element of the queue(without deleting it from the
queue) using an array (Peep operation).
4. Write a program to display the elements of a
queue using an array.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1; // Initialize front and rear pointers

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to insert an element into the queue (Enqueue operation)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0; // Initialize front when the first element is added
    }
    queue[++rear] = value;
    printf("%d enqueued into the queue.\n", value);
}

// Function to delete an element from the queue (Dequeue operation)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front]);
    if (front == rear) {
        // Reset the queue when it becomes empty
        front = rear = -1;
    } else {
        front++;
    }
}

// Function to return the front element of the queue (Peep operation)
void peep() {
    if (isEmpty()) {
        printf("The queue is empty. No front element.\n");
    } else {
        printf("The front element is %d.\n", queue[front]);
    }
}

// Function to display all elements of the queue
void display() {
    if (isEmpty()) {
        printf("The queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peep (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
