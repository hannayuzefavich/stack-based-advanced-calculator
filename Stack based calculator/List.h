#pragma once
#include "ListNode.h"
class List
{
private:
	ListNode* head;
	ListNode* tail;
	int size;
public: 
	List() : head(nullptr), tail(nullptr), size(0) {}
	ListNode* getHead();
	ListNode* getTail();
	int getSize();
	void addElement(char element);
	void setHead(ListNode* head);
	void setTail(ListNode* tail);
	char getByIndex(int index);
	void print();
	~List();	
};

