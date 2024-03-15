#include "Node.h"

Node::Node(char inputData, Node* inputPrev) {
	this->data = inputData;
	this->prev = inputPrev;
}

Node* Node::getPrev() {
	return this->prev;
}

char Node::getData() {
	return this->data;
}

void Node::setData(char data) {
	this->data = data;
}

void Node::setPrev(Node* prev) {
	this->prev = prev;
}

Node::~Node() {
	delete this->prev;
}
