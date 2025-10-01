#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Stack {
    int top;
    int items[MAX];
} Stack;

// Initialize stack
void init(Stack* s) { s->top = -1; }

// Check if stack is full
int isFull(Stack* s) { return s->top == MAX - 1; }

// Check if stack is empty
int isEmpty(Stack* s) { return s->top == -1; }

// Push element
void push(Stack* s, int val) {
    if (isFull(s)) printf("Stack Overflow\n");
    else s->items[++s->top] = val;
}

// Pop element
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

// Peek top element
int peek(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->items[s->top];
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    return 0;
}
