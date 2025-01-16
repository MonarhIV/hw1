#include "adapter4queue.h"

Adapter4Queue::Adapter4Queue() {
    qu = new Queue();
}
void Adapter4Queue::push(int x)
{
    qu->push(x);
}
void Adapter4Queue::pop() {
    qu->pop();
}
int Adapter4Queue::size() {
    return qu->size();
}
void Adapter4Queue::display() {
    int size = qu->size();
    queue <int> *quTmp1 = new queue<int>();
    for (int i = 0; i < size; i++) {
        cout << qu->front() << " ";
        quTmp1->push(qu->front());
        qu->pop();
    }
    for (int i = 0; i < size; i++) {
        qu->push(quTmp1->front());
        quTmp1->pop();
    }
    delete(quTmp1);
}
int Adapter4Queue::getElement(int ind) {
    int size = qu->size();
    int element = -1;
    if ((ind >= 0) and (ind < size)) {
        queue <int>* quTmp1 = new queue<int>();
        
        for (int i = 0; i <= ind; i++) {
            element = qu->front();
            qu->pop();
            quTmp1->push(element);
            
        }
        for (int i = ind; i < size-1; i++) {
            quTmp1->push(qu->front());
            qu->pop();
        }
        for (int i = 0; i < size; i++) {
            qu->push(quTmp1->front());
            quTmp1->pop();
        }
        return element;
    }
    return -1;
}
int Adapter4Queue::setElement(int ind, int element) {
    int size = qu->size();
    if ((ind >= 0) and (ind < size)) {
        queue <int>* quTmp1 = new queue<int>();
        for (int i = 0; i < ind; i++) {
            int elTmp = qu->front();
            qu->pop();
            quTmp1->push(elTmp);
        }
        quTmp1->push(element);
        qu->pop();
        for (int i = ind; i < size - 1; i++) {
            quTmp1->push(qu->front());
            qu->pop();
        }
        for (int i = 0; i < size; i++) {
            qu->push(quTmp1->front());
            quTmp1->pop();
        }
        return element;
    }
    return -1;
}

void Adapter4Queue::countingSort() {
    int maxElement = 0;
    for (int i = 0; i < size(); ++i) {
        maxElement = max(maxElement, getElement(i));
    }

    int* count = new int[maxElement + 1]();
    
    for (int i = 0; i < size(); ++i) {
        count[getElement(i)]++;
    }

    int index = 0;
    for (int i = 0; i <= maxElement; ++i) {
        while (count[i] > 0) {
            setElement(index++, i);
            count[i]--;
        }
    }

    delete[] count;
}
