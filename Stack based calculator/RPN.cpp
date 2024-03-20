#include "RPN.h"
#include <iostream>
#define ASCII_CAPITAL_LETTERS_BOTTOM_LIMIT 65
#define ASCII_CAPITAL_LETTERS_TOP_LIMIT 90

RPN::RPN(CustomString infix) {
	this->convertToPostfix(infix);
}

void RPN::convertToPostfix(CustomString infix) {//change the logic from chars array to linked list string
	Stack stack;
	for (int i = 0; i < infix.getSize(); i++) {
		char actualSign = infix.getByIndex(i);
		if (actualSign == ',') {
			continue;
		}
		if (isOperator(actualSign)) {
			int priority = this->getPriority(actualSign);
			if (!stack.isEmpty()) {
				int lastOnStackPriority = getPriority(stack.getTopElement());
				while (lastOnStackPriority >= priority) {
					postfix.addElement(stack.getTopElement());
					stack.pop();
					if (stack.isEmpty()) {
						break;
					}
					lastOnStackPriority = getPriority(stack.getTopElement());
				}
			}
			if(actualSign >= ASCII_CAPITAL_LETTERS_BOTTOM_LIMIT && actualSign <= ASCII_CAPITAL_LETTERS_TOP_LIMIT) {
				switch (actualSign) {
				case 'M':
					actualSign = infix.getByIndex(i + 1);
					i += 2;
					break;
				case 'I':
					actualSign = infix.getByIndex(i + 1);
					i++;
					break;				
				}
			}
			stack.push(actualSign);
		}
		else if (actualSign == '(') {
			stack.push(actualSign);
		}
		else if (actualSign == ')') {
			while (!stack.isEmpty() && stack.getTopElement() != '(') {
				postfix.addElement(stack.getTopElement());
				stack.pop();								
			}
			stack.pop();
		}		
		else {
			postfix.addElement(actualSign);
		}
	}
	while (!stack.isEmpty()) {
		postfix.addElement(stack.getTopElement());
		stack.pop();
	}
}

int RPN::getPriority(char sign) {//MIN MAX IF NEG
	if (sign >= ASCII_CAPITAL_LETTERS_BOTTOM_LIMIT && sign <= ASCII_CAPITAL_LETTERS_TOP_LIMIT) {
		return 3;
	}
	else if (sign == '*' || sign == '/') {
		return 2;
	} 
	else if (sign == '+' || sign == '-') {
		return 1;
	}
	return 0;
}

bool RPN::isOperator(char sign) {
	return sign == '*' || sign == '/' || sign == '+' || sign == '-' || (sign >= ASCII_CAPITAL_LETTERS_BOTTOM_LIMIT && sign <= ASCII_CAPITAL_LETTERS_TOP_LIMIT);
}

void RPN::print() {
	this->postfix.print();
}
