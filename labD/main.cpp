#include <stdio.h>

#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string urgency, problem;
    char repeat;
    int problem_code, problem_duration;

    do {

        cout << "Enter code: ";
        cin >> problem_code;
        cout << "Enter problem duration: ";
        cin >> problem_duration;

        switch(problem_code) {
        case 1:
        case 2:
        case 3: {
            problem = "IR malfunction";
            break;
        }
        case 4: {
            problem = "receiver malfunction";
            break;
        }
        case 5:
        case 6:
        case 7:
        case 8: {
            problem = "low battery";
            break;
        }
        default: {
            problem = "unknown malfunction";
            break;
        }
        }

        if(problem_duration <= 7) {
            urgency = "low";
            if(problem_code == 1 || problem_code == 3) {
                urgency = "very low";
            }
        } else if(problem_duration <= 14) {
            urgency = "medium";
            if(problem_code == 6 || problem_code == 7) {
                urgency = "high";
            }
        } else if(problem_duration > 14) {
            urgency = "high";
        } else {
            cout << "This is not supposed to happen.";
        }

        /*
        Your output will look like:

        "New UUU urgency request for PPP."

        ***Replace UUU with the urgency (very low, low, medium, or high).
        ***Replace PPP with the problem (IR malfunction, receiver malfunction, low battery, or unknown malfunction).
        You will then ask the user if they want to document another problem:

        "Enter another code? "

        If the user types anything but 'n' or 'N', repeat the program. Otherwise, end the program.
        */

        cout << "New " << urgency << " urgency request for " << problem << "." << endl;

        cout << "Enter another code? ";
        cin >> repeat;

    } while(repeat != 'n' && repeat != 'N');

    return 0;
}
