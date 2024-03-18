#include "ListNode.h"

ListNode::ListNode(){}

ListNode::ListNode(char character, ListNode* next) {
	this->character = character;
	this->next = next;
}

char ListNode::getCharacter() {
	return this->character;
}

ListNode* ListNode::getNext() {
	return this->next;
}

void ListNode::setNext(ListNode* next) {
	this->next = next;
}

ListNode::~ListNode() {
	
}
