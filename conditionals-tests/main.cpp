#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    char gender;
    int fcount = 0, mcount = 0;
    cout << "Enter gender: ";
    cin >> gender;
    if(gender == 'F')
        fcount++;
    else
        mcount++;

    cout << "There are " << fcount << " females and " << mcount << " males.";
    return 0;
}
