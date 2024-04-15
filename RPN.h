#pragma once
#include "CustomStack.h"
#include "ListCustomString.h"


class RPN
{
private:
	ListCustomString infix, postfix;

	bool isDigit(const char character);
	bool isMinOrMax(const CustomString& op);
	bool isOperator(const CustomString& op);
	bool isFunction(const CustomString& fun);
	bool isEqual(const CustomString& custom_string, const char* const_char);
	int getPriority(const CustomString& oper);
	int power(int a, int b);
public:
	int customStringToInt(const CustomString& oper);
public:
	RPN(const ListCustomString& infix);

	void infixToPostfix();
	bool calculatePostfix();
	

	void print();
};

