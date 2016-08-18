#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    double cost;
    double money;
    double change;
    // Requests Enter cost $
    cout << "Enter cost $";
    cin >> cost;
    
    // Requests Enter money $
    cout << "Enter money $";
    cin >> money;
    
    // Calculate change
    change = money - cost;
    
    cout << "Change = $" << change << endl;
    
	return 0;
}
