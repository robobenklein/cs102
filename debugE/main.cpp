// Debug E
// A program that implements functions
// Johnny A. Student

#include <iomanip>
#include <iostream>
// S: My compiler doesn't seem to be able to find the rand() function
// S: and I can't remember what to include for it
// A: Using 'random' as the library
#include <random>

using namespace std;

// S: My compiler is telling me that getNumber isn't defined, but
// S: I have it below!?
// A: Add a prototype before, so that the compiler knows what to expect.
int getNumber(int min, int max);

int main()
{
    char ans;
    int seed;
    int num;

    cout << "Enter seed: ";
    cin >> seed;

    srand(seed);

    do {
        int min, max;
        cout << endl;
        cout << "Enter minimum: ";
        cin >> min;
        cout << "Enter maximum: ";
        cin >> max;

        cout << endl << endl;

        num = getNumber(min, max);
        // S: The number printed below seems to always be the same and is
        // S: garbage!
        // A: we haven't defined 'num' in this scope, assign the output of getNumber() to it.
        cout << "Random number = " << num << endl;
        cout << "New random number? ";
        cin >> ans;

        // S: This do/while loop never quits!
        // A: using the wrong logical operator here, use AND not OR
    } while(ans != 'n' && ans != 'N');

    return 0;
}

int getNumber(int min, int max)
{
    // S: This seems to return numbers that are too low by
    // S: exactly 1, what was the formula again?
    // A: rand() returns a value between 0.0 and 1.0, but is not inclusive, and if min
    // A: and max are the same value, then it will attempt %0
    return min + (rand() % ((max + 1) - min));
}