#include <iostream>
#include <stdio.h>

using namespace std;

void menu_select(int& choice);

class math_stack
{

    int left = 0, right = 0, resultnum = 0;

public:
    // Access functions
    void setLeft(int new_left);
    void setRight(int new_right);
    int getResult();

    // Operations
    void Multiply();
    void Divide();
    void Add();
    void Subtract();
    void Exponent();
};

int main(int argc, char** argv)
{
    int operation;
    // Get operation:
    menu_select(operation);

    if(operation == 6) {
        return 0;
    }
    // Get operands:

    return 0;
}

void menu_select(int& choice)
{
    cout << "1. Add\n"
            "2. Subtract\n"
            "3. Multiply\n"
            "4. Divide\n"
            "5. Exponent\n"
            "6. Quit"
         << endl;
    cout << "Enter operation:";
    cin >> choice;
}

// Access functions
void math_stack::setLeft(int new_left) {};
void math_stack::setRight(int new_right) {};
int math_stack::getResult() {};

// Operations for math_stack

void math_stack::Multiply(){};
void math_stack::Divide(){};
void math_stack::Add(){};
void math_stack::Subtract(){};
void math_stack::Exponent(){};
