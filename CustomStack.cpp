#include "CustomStack.h"

CustomStack::CustomStack()
{
	this->tail = nullptr;
	this->size = 0;
}

CustomStack::~CustomStack()
{
	while (this->tail != nullptr)
	{
		CustomStackNode* to_delete = this->tail;
		this->tail = this->tail->getPrev();
		delete to_delete;
	}
}

void CustomStack::addElement(const CustomString& new_element, int counter)
{
	CustomStackNode* new_tail = new CustomStackNode(new_element, counter);

	new_tail->setPrev(this->tail);

	this->tail = new_tail;
	this->size++;
}

void CustomStack::pop()
{
	CustomStackNode* new_tail = this->tail->getPrev();

	delete this->tail;

	this->tail = new_tail;
	this->size--;
}

CustomString CustomStack::getTop()
{
	return this->tail->getElement();
}

CustomStackNode* CustomStack::getTopNode()
{
	return this->tail;
}

bool CustomStack::isEmpty()
{
	return not (bool)this->size;
}

void CustomStack::print()
{
	cout << "[";
	CustomStackNode* current = this->tail;

	while (current != nullptr)
	{
		current->getElement().print();

		if (current->getPrev() != nullptr)
		{
			cout << ", ";
		}
		current = current->getPrev();
	}
	cout << "]";
}
