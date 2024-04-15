#pragma once
#include "CustomString.h"

class CustomStackNode
{
private:
	CustomString custom_string;
	int counter;
	CustomStackNode* prev;

public:
	CustomStackNode();
	CustomStackNode(const CustomString& new_custom_string, int new_count = 0);

	void increaseCounter();

	CustomStackNode* getPrev();
	CustomString getElement();
	int getCounter();

	void setPrev(CustomStackNode* new_prev);
};

