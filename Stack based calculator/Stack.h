#pragma once
#include "Node.h"
class Stack {
private:
	Node* top;
	int size;
public:
	Stack() : top(nullptr), size(0) {}
	bool isEmpty();
	char getTop();
	void push(char element);
	void pop();
	~Stack();
};

