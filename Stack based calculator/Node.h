#pragma once
class Node {
private:
	char data;
	Node* prev;
public:
	Node(char inputData, Node* inputPrev);
	Node* getPrev();
	char getData();
	void setData(char data);
	void setPrev(Node* prev);
	~Node();
};

