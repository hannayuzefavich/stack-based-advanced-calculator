#include "CustomString.h"
#include <iostream>

CustomString::CustomString(){}

CustomString::CustomString(char* arr) {
	for (int i = 0; arr[i] != '.'; i++) {	
		if (arr[i] == ' ') {
			continue;
		}
		list.addElement(arr[i]);
	}
}

int CustomString::getSize() {
    return this->list.getSize();
}

void CustomString::addElement(char element) {
	if (element == ' ') {
		return;
	}
	this->list.addElement(element);
}

void CustomString::print() {
	this->list.print();
}

char CustomString::getByIndex(int index) {
	return this->list.getByIndex(index);
}

CustomString::~CustomString(){}

