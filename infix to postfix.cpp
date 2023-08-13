#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;
void push(char c) 
{
    if (top >= MAX_SIZE - 1) 
	{
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}
char pop() 
{
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}
int priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
void infix_to_postfix(char *infix, char *postfix) {
    char c, temp;
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while ((temp = pop()) != '(') {
                postfix[j++] = temp;
            }
        } else {
            while (top >= 0 && priority(stack[top]) >= priority(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main() 
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}


