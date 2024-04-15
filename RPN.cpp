#include "RPN.h"

RPN::RPN(const ListCustomString& infix)
{
	for (int i = 0; i < infix.getSize(); i++)
	{
		this->infix.addElement(infix.getByIndex(i));
	}
}

void RPN::infixToPostfix()
{
	CustomStack op_stack, args_stack;
	//int nesting_counter;

	for (int i = 0; i < this->infix.getSize(); i++)
	{
		CustomString actual = this->infix.getByIndex(i);

		if (isDigit(actual.getByIndex(0)))
		{
			this->postfix.addElement(actual);
		}
		else if (isFunction(actual))
		{
			op_stack.addElement(actual);
			args_stack.addElement(actual, 1);
		}
		else if (isOperator(actual))
		{
			if (not op_stack.isEmpty() and isEqual(actual, "N") and isEqual(op_stack.getTop(), "N"))
			{
				op_stack.addElement(actual);
				continue;
			}
			while (not op_stack.isEmpty() and isOperator(op_stack.getTop()) and getPriority(op_stack.getTop()) >= getPriority(actual))
			{
				this->postfix.addElement(op_stack.getTop());
				op_stack.pop();
			}
			op_stack.addElement(actual);
		}
		else if (isEqual(actual, "("))
		{
			op_stack.addElement(actual);
		}
		else if (isEqual(actual, ")"))
		{
			while (not isEqual(op_stack.getTop(), "("))
			{
				this->postfix.addElement(op_stack.getTop());
				op_stack.pop();
			}
			op_stack.pop();
			if (not op_stack.isEmpty() and isFunction(op_stack.getTop()))
			{
				CustomString temp(op_stack.getTop());
				if (isFunction(temp))
				{
					if (isMinOrMax(temp))
					{
						temp.addCharacter(args_stack.getTopNode()->getCounter());
					}
					args_stack.pop();
				}
				
				this->postfix.addElement(temp);

				op_stack.pop();
			}
		}
		else if (isEqual(actual, ","))
		{
			while (not op_stack.isEmpty() and not isEqual(op_stack.getTop(), "("))
			{
				CustomString temp(op_stack.getTop());

				if (isFunction(temp))
				{
					if (isMinOrMax(temp))
					{
						temp.addCharacter(args_stack.getTopNode()->getCounter());
					}
					args_stack.pop();
				}
				this->postfix.addElement(temp);
				op_stack.pop();
			}

			if (not args_stack.isEmpty())
			{
				args_stack.getTopNode()->increaseCounter();
			}
		}
	}

	while (not op_stack.isEmpty())
	{
		this->postfix.addElement(op_stack.getTop());
		op_stack.pop();
	}
}


bool RPN::isDigit(const char character)
{
	return character >= '0' and character <= '9';
}

bool RPN::isMinOrMax(const CustomString& fun)
{
	return isEqual(fun, "MIN") or isEqual(fun, "MAX");
}

bool RPN::isOperator(const CustomString& op)
{
	return isEqual(op, "+") or isEqual(op, "-") or isEqual(op, "*") or isEqual(op, "/") or isEqual(op, "N");
}

bool RPN::isFunction(const CustomString& fun)
{
	return isEqual(fun, "MAX") or isEqual(fun, "MIN") or isEqual(fun, "IF");
}

bool RPN::isEqual(const CustomString& custom_string, const char* const_char)
{
	int i = 0;
	while (const_char[i] != '\0' and i < custom_string.getSize())
	{
		if (const_char[i] != custom_string.getByIndex(i))
		{
			return false;
		}
		i++;
	}

	if (i != custom_string.getSize())
	{
		return false;
	}

	return true;
}

int RPN::getPriority(const CustomString& oper)
{
	if (isEqual(oper, "+") or isEqual(oper, "-")) return 1;

	if (isEqual(oper, "*") or isEqual(oper, "/")) return 2;

	if (isEqual(oper, "MAX") or isEqual(oper, "MIN") or isEqual(oper, "IF") or isEqual(oper, "N")) return 3;
	return -1;
}

int RPN::power(int a, int b) 
{
	int res = 1;
	for (int i = 0; i < b; i++) 
	{
		res *= a;
	}
	return res;
}

int RPN::customStringToInt(const CustomString& oper) 
{
	int result = 0;
	int size = oper.getSize();
	bool is_negative = false;
	int i = 0;
	if (oper.getByIndex(0) == '-') 
	{
		is_negative = true;
		i = 1;
	}
	for (i ; i < size; i++) 
	{
		result += (oper.getByIndex(i) - '0') * power(10, size-(i+1));
	}
	if (is_negative) 
	{
		result *= -1;
	}
	return result;
}

bool RPN::calculatePostfix() 
{
	for (int i = 0; i < postfix.getSize(); i++) 
	{
		CustomString str = postfix.getByIndex(i);
		if (isOperator(str)) {
			CustomString result;		
			int a = customStringToInt(postfix.getByIndex(i - 2));
			int b = customStringToInt(postfix.getByIndex(i - 1));
			bool is_N = false;
			postfix.printPart(i);
			cout << endl;
			switch (str.getByIndex(0)) 
			{
			case '+':							
				result.addCharacter(a + b);	
				break;
			case '-':			
				result.addCharacter(a - b);
				break;
			case '/':
				if (b == 0) 
				{
					cout << "ERROR";
					return false;
				}
				result.addCharacter(a / b);
				break;
			case '*':
				result.addCharacter(a * b);
				break;
			case 'N':
				is_N = true;
				result.addCharacter(b * (-1));
				break;
			}
			postfix.insert(i + 1, result);
			
			
			if (is_N) {
				for (int j = 0; j < 2; j++) 
				{
					postfix.pop(i - 1);
				}
			}
			else {
				for (int j = 0; j < 3; j++) 
				{
					postfix.pop(i - 2);
					
				}
			}
			
			i=0;
		}
		else if (isDigit(str.getByIndex(0)) or str.getByIndex(0) == '-') 
		{
			continue;
		}
		else 
		{
			CustomString functionType;
			CustomString s_argsNum;
			postfix.printPart(i);
			cout << endl;
			if (str.getByIndex(0) == 'M') 
			{				
				int j = 0;
				while (not isDigit(str.getByIndex(j))) 
				{
					functionType.addCharacter(str.getByIndex(j));
					j++;
				}
				for (j; j < str.getSize(); j++) 
				{
					s_argsNum.addCharacter(str.getByIndex(j));
				}
			}
			else 
			{
				functionType.merge(str);
			}
			if (isEqual(functionType, "MIN"))
			{
				int argsNum = customStringToInt(s_argsNum);
				int min = customStringToInt(postfix.getByIndex(i-1));
				int temp;
				CustomString result;
				for (int j = i - 2; j >= i - argsNum; j--)
				{
					temp = customStringToInt(postfix.getByIndex(j));
					if (temp < min) 
					{
						min = temp;
					}				
				}
				result.addCharacter(min);
				postfix.insert(i + 1, result);
				for (int j = 0; j < argsNum + 1; j++) 
				{
					postfix.pop(i - argsNum);
					
				}
				i=0;			
			}
			else if (isEqual(functionType, "MAX"))
			{
				int argsNum = customStringToInt(s_argsNum);
				int max = customStringToInt(postfix.getByIndex(i - 1));
				int temp;
				CustomString result;
				for (int j = i - 2; j >= i - argsNum; j--) 
				{
					temp = customStringToInt(postfix.getByIndex(j));
					if (temp > max) 
					{
						max = temp;
					}
				}
				result.addCharacter(max);
				postfix.insert(i + 1, result);
				
				for (int j = 0; j < argsNum + 1; j++) 
				{
					postfix.pop(i - argsNum);
					
				}
				i=0;
			}
			else if (isEqual(functionType, "IF")) 
			{
				int argsNum = 3;
				CustomString result;
				int a = customStringToInt(postfix.getByIndex(i - 3));
				if (a > 0) 
				{
					result.merge(postfix.getByIndex(i - 2));
				}
				else 
				{
					result.merge(postfix.getByIndex(i - 1));
				}
				postfix.insert(i + 1, result);
				for (int j = 0; j < argsNum + 1; j++) 
				{
					postfix.pop(i - argsNum);
				}
				i=0;
			}
		}
	}
	return true;
}

void RPN::print()
{
	this->postfix.print();
}
