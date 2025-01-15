#pragma once
#include <queue>
#include <iostream>
using namespace std;
class Queue
{
	queue <int>* qu;
public:
	Queue();
	void push(int element);
	int front();
	int size();
	void pop();
	void Display();
};