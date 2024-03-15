#include "RPN.h"



int main() {


	CustomString cString;
	cString.addElement('1');
	cString.addElement('+');
	cString.addElement('2');
	RPN rpn(cString);
	rpn.print();


	return 0;
}