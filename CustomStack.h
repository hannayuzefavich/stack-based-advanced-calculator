#pragma once
#include "CustomStackNode.h"


class CustomStack
{
private:
	CustomStackNode* tail;
	int size;

public:
	CustomStack();
	~CustomStack();

	void addElement(const CustomString& new_element, int counter = 0);
	void pop();

	CustomString getTop();
	CustomStackNode* getTopNode();
	bool isEmpty();

	void print();
};

