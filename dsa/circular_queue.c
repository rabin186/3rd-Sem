#include <stdio.h>

struct cqueue {
    int rear;
    int front;
    int item[100];
};
typedef struct cqueue cque;

void enqueue(cque *q, int n) {
    int data;
    if ((q->rear + 1) % (n + 1) == q->front) {
        printf("Queue Overflow.\n");
        return;
    } 
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    
    q->item[q->rear] = data;
    q->rear = (q->rear + 1) % (n + 1); 
}

void dequeue(cque *q, int n) {
    if (q->rear == q->front) {
        printf("The queue is empty.\n");
        return;
    }
    printf("The deleted item is: %d\n", q->item[q->front]);
    q->front = (q->front + 1) % (n + 1);
}

void display(cque *q, int n) {
    if (q->rear == q->front) {
        printf("The queue is empty.\n");
        return;
    }
    printf("The elements in the circular queue are: ");
    for (int i = q->front; i != q->rear; i = (i + 1) % (n + 1)) { 
        printf("%d\t", q->item[i]);
    }
    printf("\n");
}

int main() {
    int choice = 0, n;
    cque q;  

    printf("Enter the number of elements of Circular Queue: ");
    scanf("%d", &n);

    q.rear = q.front = 0;

    printf("\n********* Circular Queue Operation Using Array *********\n");

    while (choice != 4) {
        printf("\nPlease choose an operation:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&q, n);
                break;
            case 2:
                dequeue(&q, n);
                break;
            case 3:
                display(&q, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    }

    printf("\n-----------------------------------\n");
    printf("Programmed By Rabin Acharya.\n");
    return 0;
}

