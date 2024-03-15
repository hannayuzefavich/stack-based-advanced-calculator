#pragma once
#include "List.h"
class CustomString
{
private:
	List list;
public:
	CustomString();
	CustomString(char* arr);
	int getSize();
	void addElement(char element);
	void print();
	char getByIndex(int index);
	~CustomString();
};

