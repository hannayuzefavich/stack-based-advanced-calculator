#pragma once
class ListNode
{
private:
	char character;
	ListNode* next;
public:
	ListNode();
	ListNode(char character, ListNode* next);
	char getCharacter();
	ListNode* getNext();
	void setNext(ListNode* next);
	~ListNode();
};

