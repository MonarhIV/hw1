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
    int n = 0;

    if (size() == 0) {
        cerr << "Ошибка: очередь пуста." << endl;
        return;
    }

    n++; // size()
    int maxElement = 0;
    n++;

    for (int i = 0; i < size(); ++i) {
        n++; // size()
        n++; // i < size()
        n++; // getElement(i)
        maxElement = max(maxElement, getElement(i));
        n++; // max()
        n++;
    }

    n++; // i < size() false

    if (maxElement < 0) {
        cerr << "error: maxElement <0." << endl;
        return;
    }

    try {
        n++; // maxElement + 1
        int* count = new int[maxElement + 1]();
        n++;

        for (int i = 0; i < size(); ++i) {
            n++; // size()
            n++; // i < size()
            n++; // getElement(i)
            n++; // count[getElement(i)]
            count[getElement(i)]++;
            n++;
        }

        n++; // i < size() false

        int index = 0;
        n++;

        for (int i = 0; i <= maxElement; ++i) {
            n++; // i <= maxElement
            while (count[i] > 0) {
                n++; // count[i]
                n++; // count[i] > 0
                n++; // setElement()
                setElement(index++, i);
                n++;
                n++; // count[i]
                count[i]--;
                n++;
            }
            n++; // count[i] > 0 false
        }

        n++; // i <= maxElement false

        delete[] count;
    } catch (const std::bad_array_new_length& e) {
        cerr << "error mem: " << e.what() << endl;
    }

    cout << "N_op: " << n << endl;
}
