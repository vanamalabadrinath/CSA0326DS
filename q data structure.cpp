#include <stdio.h>
#define MAXSIZE 100

int queue[MAXSIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear >= MAXSIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front++;
    }
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    int temp = queue[front];
    front++;
    return temp;
}

int peek() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front];
}

int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, i, value;
    printf("Enter the number of elements you want to enqueue: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);
        enqueue(value);
    }
    printf("Front of queue: %d\n", peek());
    printf("Dequeuing: %d\n", dequeue());
    printf("Front of queue: %d\n", peek());
    printf("Enter another element to enqueue: ");
    scanf("%d", &value);
    enqueue(value);
    printf("Is queue empty? %d\n", isEmpty());
    while (!isEmpty()) {
        printf("Dequeuing: %d\n", dequeue());
    }
    printf("Is queue empty? %d\n", isEmpty());
    return 0;
}

