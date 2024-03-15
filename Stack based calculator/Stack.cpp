#include "Stack.h"

bool Stack::isEmpty() {
	return top == nullptr;
}

char Stack::getTop() {
	return this->top->getData();
}

void Stack::push(char element) {
	Node* newNode = new Node(element, nullptr);
	if (this->isEmpty()) {
		
		this->top = newNode;
	}
	//no need to find last, just add to the top and reassign the pointer?
	else {
		Node* current = top;
		while (current->getPrev() != nullptr) {
			current = current->getPrev();
		}
		current->setPrev(newNode);
	}
	this->size++;
}

void Stack::pop() {
	/*if (this->isEmpty()) {
		
	}*/
	Node* temp = top;
	top = top->getPrev(); 
	this->size--;
	delete temp;
}

Stack::~Stack() {
	//while?
	if (!isEmpty()) {
		pop();
	}
}
