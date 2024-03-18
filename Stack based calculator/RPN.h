#pragma once
#include "Stack.h"
#include "CustomString.h"
class RPN {
private:
	CustomString postfix;
public:
	RPN() {}
	RPN(CustomString postfix);
	int getPriority(char sign);
	bool isOperator(char sign);
	void convertToPostfix(CustomString infix);
	void print();
	~RPN() {}
};

