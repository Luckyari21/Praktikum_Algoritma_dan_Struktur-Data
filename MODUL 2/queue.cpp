#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = q->data;
    q->rear  = q->data - 1;
}

bool isEmpty(const Queue* q) {
    return q->front > q->rear;
}

bool isFull(const Queue* q) {
    return q->rear >= q->data + MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q))
        throw std::overflow_error("Queue penuh");
    *(++q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q))
        throw std::underflow_error("Queue kosong");
    q->front++;
}

int front(const Queue* q) {
    if (isEmpty(q))
        throw std::underflow_error("Queue kosong");
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q))
        throw std::underflow_error("Queue kosong");
    return *(q->rear);
}