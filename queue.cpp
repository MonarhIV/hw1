#include "queue.h"

Queue::Queue() {
    qu = new queue<int>();
}

void Queue::push(int element) {
    qu->push(element);
}

int Queue::front() {
    return qu->front();
}

int Queue::size() {
    return qu->size();
}

void Queue::pop() {
    qu->pop();
}

void Queue::Display() {
    Queue* queTmp1 = new Queue();
    int c_size = size();
    for (int i = 0; i < c_size; i++) {
        queTmp1->push(front());
        cout << " " << front();
        pop();
    }
    for (int i = 0; i < c_size; i++) {
        push(queTmp1->front());
        queTmp1->pop();
    }
    delete queTmp1;
}