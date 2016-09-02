#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    double cost, money;
    double max_cost = 100000.00;

    cost = max_cost + 1.00;
    money = -1.00;

    /*
    Ask the user two questions for inputs cost and money

    "Enter cost $"
    "Enter money $"

    ***Notice that there is NO SPACE after the dollar sign ($).

    Ensure that cost meets the following requirements:

    Use a do/while loop to ensure that the cost is less than or equal to $100,000.00
    If the user inputs something bigger than $100,000.00, simply re-prompt "Enter cost $"
    Continue this process until the user gives you a value less than or equal to $100,000.00
    Ensure that money meets the following requirements:

    Use another do/while loop to ensure that the money is bigger than 0.
    A user must not be able to pay $0 or a negative value
    If the user inputs something less than or equal to $0.00, re-prompt "Enter money $"
    Continue this process until the user gives you a money value bigger than $0.00
    ***After all inputs are verified to be correct, output a new line by using cout << endl;
    */

    while(not(cost <= max_cost)) {
        cout << "Enter cost $";
        cin >> cost;
    }
    while(not(money > 0.00)) {
        cout << "Enter money $";
        cin >> money;
    }

    // Done getting inputs.
    cout << endl;

    double change = money - cost;

    // Ensure money will print correctly.
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Check amount of change, if else,
    if(change == 0.00) {
        cout << "Customer paid exact change.";
    } else if(change < 0.00) {
        cout << "Customer did not give you enough money.";
    } else {
        cout << "Give the customer $" << change << ".";
    }
}
