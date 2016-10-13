#include <cmath>
#include <iostream>
#include <stdio.h>

using namespace std;

void menu_select(int& choice);

class math_stack
{

    double left = 0.0, right = 0.0, resultnum = 0.0;

public:
    // Access functions
    void setLeft(double new_left);
    void setRight(double new_right);
    double getResult();

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
    double left, right;
    math_stack maththing;

    while(operation != 6) {
        // Get operation:
        menu_select(operation);

        while(operation < 1 || operation > 6) {
            menu_select(operation);
        }
        // Do we quit?
        if(operation == 6) {
            break;
        }

        // Two operands on the same line.
        cout << "Enter operands: ";
        cin >> left >> right;
        maththing.setLeft(left);
        maththing.setRight(right);

        switch(operation) {
        case 1:
            // Add
            maththing.Add();
            break;
        case 2:
            maththing.Subtract();
            break;
        case 3:
            maththing.Multiply();
            break;
        case 4:
            maththing.Divide();
            break;
        case 5:
            maththing.Exponent();
            break;
        }

        // Done calculations
        cout << endl;
        cout << "Result = ";
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);
        cout << maththing.getResult();
        cout << endl;
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
    cout << "Enter operation: ";
    cin >> choice;
}

// Access functions

void math_stack::setLeft(double new_left)
{
    left = new_left;
};
void math_stack::setRight(double new_right)
{
    right = new_right;
};

double math_stack::getResult()
{
    return resultnum;
};

// Operations for math_stack

void math_stack::Multiply()
{
    resultnum = left * right;
};
void math_stack::Divide()
{
    resultnum = left / right;
};
void math_stack::Add()
{
    resultnum = left + right;
};
void math_stack::Subtract()
{
    resultnum = left - right;
};
void math_stack::Exponent()
{
    resultnum = pow(left, right);
};
