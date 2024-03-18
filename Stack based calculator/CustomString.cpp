#include "CustomString.h"

CustomString::CustomString(){}

CustomString::CustomString(char* arr) {

	List list;//pointers initially null as in default constructor
	for (int i = 0; arr[i] != '.'; i++) {	
		if (arr[i] == ' ') {
			i++;//continue?
		}
		list.addElement(arr[i]);
	}
}

int CustomString::getSize() {
    return this->list.getSize();
}

void CustomString::addElement(char element) {
	this->list.addElement(element);
}

void CustomString::print() {
	this->list.print();
}

char CustomString::getByIndex(int index) {
	return this->list.getByIndex(index);
}

CustomString::~CustomString(){}

