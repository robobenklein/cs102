#include <iostream>
#include <stdio.h>

using namespace std;

const double DOLLAR_THICKNESS = 0.0043;

int main(int argc, char** argv)
{
    // Init vars
    double distance, debt;
    double DOLLAR_INCHES, DOLLAR_FEET, DOLLAR_MILES, TRIPS;

    // Get inputs
    cout << "Enter distance (miles): ";
    cin >> distance;
    cout << "Enter debt ($): ";
    cin >> debt;

    // Convert
    DOLLAR_INCHES = debt * DOLLAR_THICKNESS;
    DOLLAR_FEET = DOLLAR_INCHES / 12.0;
    DOLLAR_MILES = DOLLAR_FEET / 5280.0;

    // Number of trips possible.
    TRIPS = DOLLAR_MILES / distance;

    /*
For a debt of $        XXXX.YY
and a distance of                 XXXX.YYYY miles
You can make XXX   trips.
    */

    // Print debt
    cout << "For a debt of $";
    cout.width(15);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << right << debt;
    cout << endl;

    // Print distance
    cout << "and a distance of ";
    cout.width(25);
    cout.precision(4);
    cout << right << distance << " miles";
    cout << endl;

    // Print trips
    cout << "You can make ";
    cout.width(5);
    cout.setf(ios::fixed);
    cout.unsetf(ios::showpoint);
    cout.precision(0);
    cout << left << TRIPS;
    cout << " trips.";
    cout << endl;

    return 0;
}
