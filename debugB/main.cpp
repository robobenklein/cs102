//Debug B
//A program that calculates heart rates depending on age
//Johnny A. Student

#include <iostream>
//S: What do I need to include for setprecision, setw, and fixed???
#include <fstream>
#include <string>

using namespace std;

//S: It seems that no matter whether or not I use
//S: FAT_COEFFICIENT or ATH_COEFFICIENT, I get the
//S: same answer. What happened?
//A: Ints will truncate, needs double
const double FAT_COEFFICIENT = 2.04;
const double ATH_COEFFICIENT = 2.97;

int main()
{
    //S: For some reason this doesn't work
    //S: I want the user to enter their first name
    //S: and last name.
    //A: strings are more appropriate here
    string first;
    string last;

    int age;
    double athletic_pulse;
    double fatburn_pulse;
    
    cout << "Maximum Pulse Calculator" << endl;
    cout << "Enter first and last name: ";
    cin >> first >> last;

    cout << "Enter your age: ";
    cin >> age;

    //S: Something doesn't work here, here are the steps:
    //S: 1. Subtract age from 100
    //S: 2. Multiple #1 by ***_COEFFICIENT
    //A: Order of operations
    fatburn_pulse  = (100 - age) * FAT_COEFFICIENT;
    athletic_pulse = (100 - age) * ATH_COEFFICIENT;

    //S: I want the last name and the first name
    //S: to be in a field, right-justified, 10 characters
    //S: wide. Why doesn't this work?
    //A: setw is not the correct method for doing that,
    cout.width(10);
    cout << right << last << ", ";
    cout.width(10);
    cout << right << first << endl;

    cout << "For a " << age << " year old:" << endl;

    //S: I want these in fixed notation and only 1 decimal point of precision
    //S: How again do I force fixed notation?
    //A: methods for formatting in cout lib now
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "\tFatburn Pulse = " << fatburn_pulse << endl;
    cout << "\tAthletic Pulse = " << athletic_pulse << endl;

    return 0;

}