#pragma once
#include "queue.h"
#include <iostream>
using namespace std;

class Adapter4Queue
{
	Queue *qu;
public:
	Adapter4Queue();
	void push(int x);
	int size();
	void display();
	int getElement(int ind);
	int setElement(int ind, int element);
    void countingSort();
};