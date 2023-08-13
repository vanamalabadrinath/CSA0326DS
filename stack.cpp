#include <stdio.h>
#define MAXSIZE 100

int stack[MAXSIZE];
int top = -1;

void push(int value) {
    if (top >= MAXSIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int temp = stack[top];
    top--;
    return temp;
}

int peek() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, i, value;
    printf("Enter the number of elements you want to push onto the stack: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);
        push(value);
    }
    printf("Top of stack: %d\n", peek());
    printf("Popping: %d\n", pop());
    printf("Top of stack: %d\n", peek());
    printf("Enter another element to push onto the stack: ");
    scanf("%d", &value);
    push(value);
    printf("Is stack empty? %d\n", isEmpty());
    while (!isEmpty()) {
        printf("Popping: %d\n", pop());
    }
    printf("Is stack empty? %d\n", isEmpty());
    return 0;
}

