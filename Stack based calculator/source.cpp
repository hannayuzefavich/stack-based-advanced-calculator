#include "RPN.h"
#include <iostream>
#include <iomanip>

int main() {

	/*CustomString cString;
	cString.addElement('1');
	cString.addElement('+');
	cString.addElement('2');
	RPN rpn(cString);
	rpn.print();*/
	std::cin >> std::noskipws;
	char c = '.';
	CustomString st(&c);
	while (std::cin>>c) {
		if (c =='.') {
			break;
		}
		st.addElement(c);
	}
	
	RPN rpn(st);
	rpn.print();
	/*List list;
	list.addElement('a');
	list.addElement('b');
	list.addElement('c');

	std::cout<<list.getTail()->getCharacter();*/


	return 0;
}