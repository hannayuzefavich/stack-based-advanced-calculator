#include "Stack.h"

bool Stack::isEmpty() {
	return top == nullptr;
}

char Stack::getTopElement() {
	return this->top->getData();
}

int Stack::getSize() {
	return this->size;
}

Node* Stack::getTop() {
	return this->top;
}

void Stack::push(char element) {
	Node* newNode = new Node(element, nullptr);
	if (this->isEmpty()) {	
		this->top = newNode;
	}
	else {
		newNode->setPrev(top);
		top = newNode;
	}
	this->size++;
}

void Stack::pop() {
	if (!isEmpty()) {
		Node* temp = top;
		top = top->getPrev();
		this->size--;
		delete temp;
	}	
}

Stack::~Stack() {
	//delete top;
}
