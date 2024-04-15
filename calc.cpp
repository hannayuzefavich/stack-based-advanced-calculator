#include <iostream>
#include "RPN.h"
#include "ListCustomString.h"
#include "CustomStack.h"


using namespace std;

bool CustomGetline(ListCustomString& line)
{
    char c;
    CustomString part;
    bool multiple_spaces = false;

    while (cin.get(c))
    {
        if (c == '\n')
        {
            return true;
        }
        if (c == ' ')
        {
            if (multiple_spaces == false) 
            {
                line.addElement(part);
                part.clear();
                multiple_spaces = true;
            }          
        }
        else if(c != '.')
        {
            multiple_spaces = false;
            part.addCharacter(c);
        }
    }
    return line.getSize();
}

int main()
{
    int n;
    ListCustomString a;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++) 
    {
        CustomGetline(a);
        RPN test(a);

        test.infixToPostfix();
        test.print();
        cout << endl;
        if (test.calculatePostfix()) 
        {
            test.print();
        }      
        cout << endl;
        a.clear();
    }    
}
