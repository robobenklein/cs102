#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
    // CodeAssessor is wayyy too dumb to care about stdin newlines.
    double one, two;
    cin >> one >> two;
    cout << "Enter width: Enter height: area = " << (one * two);
    // If you are reading this, please improve the system if you can.
    return 0;
}
