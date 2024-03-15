#include "List.h"
#include <iostream>
using namespace std;

ListNode* List::getHead() {
	return this->head;
}

ListNode* List::getTail() {
	return this->tail;
}

void List::setHead(ListNode* head) {
	this->head = head;
}

void List::setTail(ListNode* tail) {
	this->tail = tail;
}

int List::getSize() {
	return this->size;
}

void List::addElement(char element) {
	ListNode* node = new ListNode(element, nullptr);
	if (head == nullptr) {
		head = tail = node;
	}
	else {
		tail->setNext(node);
		tail = node;
	}
	size++;
}

char List::getByIndex(int index) {
	int i = 0;
	ListNode* current = head;
	while (current != nullptr) {
		if (i == index) {
			return current->getCharacter();
		}
		current = current->getNext();
		i++;
	}
}

void List::print() {
	ListNode* current = head;
	while (current != nullptr) {
		cout << current->getCharacter();
		current = current->getNext();
	}
}

List::~List() {
	
}
