#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Queue {
    int front, rear;
    int items[MAX];
} Queue;

// Initialize queue
void init(Queue* q) { q->front = q->rear = -1; }

// Check if empty
int isEmpty(Queue* q) { return q->front == -1; }

// Check if full
int isFull(Queue* q) { return q->rear == MAX - 1; }

// Enqueue
void enqueue(Queue* q, int val) {
    if (isFull(q)) printf("Queue Overflow\n");
    else {
        if (isEmpty(q)) q->front = 0;
        q->items[++q->rear] = val;
    }
}

// Dequeue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = q->items[q->front];
    if (q->front == q->rear) q->front = q->rear = -1; // reset
    else q->front++;
    return val;
}

int main() {
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
