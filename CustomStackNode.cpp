#include "CustomStackNode.h"

CustomStackNode::CustomStackNode()
{
	this->prev = nullptr;
	this->counter = 0;
}

CustomStackNode::CustomStackNode(const CustomString& new_custom_string, int new_counter)
{
	this->custom_string.merge(new_custom_string);
	this->counter = new_counter;
	this->prev = nullptr;
}

void CustomStackNode::increaseCounter()
{
	this->counter++;
}

CustomStackNode* CustomStackNode::getPrev()
{
	return this->prev;
}

CustomString CustomStackNode::getElement()
{
	return this->custom_string;
}

int CustomStackNode::getCounter()
{
	return this->counter;
}

void CustomStackNode::setPrev(CustomStackNode* new_prev)
{
	this->prev = new_prev;
}


