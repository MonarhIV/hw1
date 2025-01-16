#include "adapter4queue.h"
#include <iostream>
#include <cassert>

using namespace std;

// Функция для тестирования добавления элементов в очередь
void testPushElements() {
    Adapter4Queue queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);

    assert(queue.size() == 3);
    assert(queue.getElement(0) == 10);
    assert(queue.getElement(1) == 20);
    assert(queue.getElement(2) == 30);

    cout << "testPushElements passed!" << endl;
}

// Функция для тестирования сортировки
void testCountingSort() {
    Adapter4Queue queue;
    queue.push(30);
    queue.push(10);
    queue.push(20);
    queue.push(40);
    queue.push(50);

    queue.countingSort();

    assert(queue.getElement(0) == 10);
    assert(queue.getElement(1) == 20);
    assert(queue.getElement(2) == 30);
    assert(queue.getElement(3) == 40);
    assert(queue.getElement(4) == 50);

    cout << "testCountingSort passed!" << endl;
}

// Функция для тестирования изменения элемента
void testSetElement() {
    Adapter4Queue queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);

    queue.setElement(1, 99);

    assert(queue.getElement(1) == 99);

    cout << "testSetElement passed!" << endl;
}

// Функция для тестирования удаления элементов
void testPopElements() {
    Adapter4Queue queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);

    queue.pop();
    assert(queue.size() == 2);
    assert(queue.getElement(0) == 20);
    assert(queue.getElement(1) == 30);

    cout << "testPopElements passed!" << endl;
}

int main() {
    testPushElements();
    testCountingSort();
    testSetElement();
    testPopElements();

    cout << "All tests passed!" << endl;
    return 0;
}