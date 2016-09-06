// Debug D
// A program that implements a user editor
// Johnny A. Student

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    int choice;
    int amt;

    do {
        cout << "Make a choice from the following menu:" << endl;
        cout << "   1. Add a user" << endl;
        cout << "   2. Delete a user" << endl;
        cout << "   3. Modify a user" << endl;
        cout << "   4. View a user" << endl;
        cout << "   5. Contact a user" << endl;
        cin >> choice;
        // This doesn't work as it should. I want to keep looping if
        // the choice is outside of 1-5, but this seems to break the
        // loop no matter what I type.
        // A: you are using the wrong logic (use OR instead of AND)
    } while(choice < 0 || choice > 5);

    // Something is wrong here. Every time I choose 1, it gives
    // me everything. When I choose 2, it skips "add a user", but
    // then gives me delete, modify, and view a user.
    // A: You need to break the switch when you've found a match.
    switch(choice) {
    case 1: {
        cout << "You chose 'add a user'" << endl;
        break;
    }
    case 2: {
        cout << "You chose 'delete a user'" << endl;
        break;
    }
    case 3: {
        cout << "You chose 'modify a user'" << endl;
        break;
    }
    case 4: {
        cout << "You chose 'view a user'" << endl;
        break;
    }
    case 5: {
        cout << "How many users? ";
        cin >> amt;
        cout << "Enter users:" << endl;
        // This doesn't seem to work at all, what did I do?
        // I want to grab a name for each of the users that
        // the user gives me and output it with "Contacting <username>"
        // A: removed random semicolon, use < instead of <=
        for(int i = 0; i < amt; i++)
        {
            string name;
            cin >> name;
            cout << "Contacting " << name << endl;
        }
        break;
    }
    default: {
        cout << "Unknown choice: " << choice << endl;
        break;
    }
    }

    return 0;
}