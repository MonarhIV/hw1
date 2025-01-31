#include "queue.h"
#include "adapter4queue.h"
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std::chrono;

void example_work_Queue() {
   Queue q1;
   q1.push(10);
   q1.push(20);
   q1.push(30);
   q1.push(40);
   q1.push(50);
   int size = q1.size();
   cout << "Size of queue: " << size << endl;
   for (int i = 0; i < size; i++) {
       cout << q1.front() << " ";
       q1.pop();
   }
   size = q1.size();
   cout << endl << "Size of queue: " << size << endl;
}
void example_work_Adapter4Queue() {
   Adapter4Queue* ast = new Adapter4Queue();
   srand(static_cast<unsigned int>(time(0)));
   for (int i = 0; i < 500; ++i) {
        int randomNumber = rand() % 51;
        ast->push(randomNumber);
    }
   cout << endl;    ast->display();
   cout << endl << ast->setElement(3,9999);
   cout << endl;
   cout << endl;    ast->display();
   cout << endl;
   cout << endl << ast->getElement(3);
   cout << endl;
   cout << endl;    ast->display();
   auto start = high_resolution_clock::now();
   ast->countingSort();
   auto stop = high_resolution_clock::now();
   cout << endl;
   auto duration = duration_cast<microseconds>(stop - start);
   cout << endl;    ast->display();
   cout << endl << "Time taken by countingSort: " << duration.count() << " microseconds" << endl;

    delete ast;
}

void measureSortingTime(Adapter4Queue& queue, int length) {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < length; ++i) {
        int randomNumber = rand() % 51;
        queue.push(randomNumber);
    }

    auto start = high_resolution_clock::now();
    queue.countingSort();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "time countingSort for n = " << length << ": " << duration.count() << " microsec" << endl;
}

int main() {
    Adapter4Queue queue;
    example_work_Queue();
    example_work_Adapter4Queue();

    int lengths[] = {300, 600, 900, 1200, 1500, 1800, 2100, 2400, 2700, 3000};
    for (int length : lengths) {
        measureSortingTime(queue, length);
    }
    return 0;
}