// Debug F
// A program that implements classes
// Johnny A. Student

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

class Generator
{
    int high, low;

    // I want to be able to use these from int main(),
    // but I get an error!!
    // A: These are all still private, make them public like so:
public:
    void generateNumber(int& num);
    void setLow(int low);
    void setHigh(int high);
};

int main()
{
    Generator gen;
    int rd;
    int low, high;

    cout << "Enter the low number: ";
    cin >> low;

    cout << endl;
    cout << "Enter the high number: ";
    cin >> high;

    srand(low + high);

    // All of these say that setLow and setHigh are not declared
    // A: they were originally private, and as such could not be accessed.
    gen.setLow(low);
    gen.setHigh(high);

    cout << endl;
    cout << "How many numbers to generate? ";
    cin >> rd;

    cout << endl;
    for(int i = 0; i < rd; i++) {
        int k;
        // I can't get this to give me a number. k is by reference
        // so it should take the value, right? Why doesn't this print?
        // A: gen.generateNumber does not return anything, it modifies k:
        gen.generateNumber(k);
        cout << k << endl;
    }

    return 0;
}

// setLow and setHigh don't seem to take the appropriate
// value.
// A: You forgot that these functions should be inside the class, mark them using the "::" operator
// A: Let's also rename the low and high so that the variables don't intersect.
void Generator::setLow(int new_low)
{
    low = new_low;
}

void Generator::setHigh(int new_high)
{
    high = new_high;
}

void Generator::generateNumber(int& num)
{
    num = low + rand() % (high - low + 1);
}