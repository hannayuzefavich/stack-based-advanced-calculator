#include "RPN.h"
#define ASCII_NUMBERS_BOTTOM_LIMIT 48
#define ASCII_NUMBERS_TOP_LIMIT 57

RPN::RPN(CustomString infix) {
	this->convertToPostfix(infix);
}

void RPN::convertToPostfix(CustomString infix) {//change the logic from chars array to linked list string
	Stack stack;
	for (int i = 0; i < infix.getSize(); i++) {
		char actualSign = infix.getByIndex(i);
		if (isOperator(actualSign)) {
			int priority = this->getPriority(actualSign);
			if (!stack.isEmpty()) {
				int lastOnStackPriority = getPriority(stack.getTop());
				while (lastOnStackPriority >= priority) {
					postfix.addElement(stack.getTop());
					stack.pop();
					if (stack.isEmpty()) {
						break;
					}
					lastOnStackPriority = getPriority(stack.getTop());
				}
			}
			stack.push(actualSign);
		}
		else if (actualSign == '(') {
			stack.push(actualSign);
		}
		else if (actualSign == ')') {
			while (!stack.isEmpty() && stack.getTop() != '(') {
				postfix.addElement(stack.getTop());
				stack.pop();								
			}
			stack.pop();
		}
		else {
			postfix.addElement(actualSign);
		}
	}
	while (!stack.isEmpty()) {
		postfix.addElement(stack.getTop());
		stack.pop();
	}
}

int RPN::getPriority(char sign) {//MIN MAX IF NEG
	if (sign == '*' || sign == '/') {
		return 2;
	} 
	if (sign == '+' || sign == '-') {
		return 1;
	}
	return 0;
}

bool RPN::isOperator(char sign) {
	return sign == '*' || sign == '/' || sign == '+' || sign == '-';
}

void RPN::print() {
	this->postfix.print();
}
