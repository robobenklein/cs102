#include <stdio.h>
#include <iostream>

using namespace std;

class SimpleArray {
    const static int array_max_size = 30;
    string str_arr[array_max_size];

public:
    const string get_item(int index);
    bool set_item(int index, string newstring);
};

char menu_prompt();
SimpleArray new_blank_array();

int main(int argc, char **argv)
{
    char last_input = 'n';
    int index;
    string newstring, outputstring;
    SimpleArray myarray;
    bool returncode;

    myarray = new_blank_array();

    // Main loop
    while (last_input != 'q') {
        last_input = menu_prompt();
        // Check for quit first, breaks the outermost while.
        if (last_input == 'q') {
            break;
        }
        // Needs to check a boolean return code
        else if (last_input == 's') {
            cin >> index >> newstring;
            returncode = myarray.set_item(index, newstring);
            if (returncode == false) {
                cout << "Unable to set index " << index << endl;
            }
        }
        // Needs to check value of string for an error.
        else if (last_input == 'g') {
            cin >> index;
            outputstring = myarray.get_item(index);
            if (outputstring == "ERROR") {
                cout << "Unable to get index " << index << endl;
            } else {
                cout << "Element " << index << " = " << outputstring << endl;
            }

        }
    }
	return 0;
}

char menu_prompt () {
    char user_input = 'n';

    while (user_input != 's' && user_input != 'g' && user_input != 'q') {
        cout << "s index value - Set a value in the array" << endl;
        cout << "g index - Get a value in the array" << endl;
        cout << "q - Quit" << endl;
        cin >> user_input;
    }

    return user_input;
}

// These only check for potential out-of-bounds exceptions, nothing else.
bool SimpleArray::set_item(int index, string newstring) {
    if (index < 1 || index > array_max_size) {
        return false;
    } else {
        str_arr[index - 1] = newstring;
        return true;
    }
}

const string SimpleArray::get_item(int index) {
    if (index < 1 || index > array_max_size) {
        return "ERROR";
    } else {
        return str_arr[index - 1];
    }
}

SimpleArray new_blank_array() {
    SimpleArray output_array;
    int i = 1;
    // Take advantage of the built-in boolean return of SimpleArray,
    // May not be the solution you were looking for, but works no matter the max_size.
    while (output_array.set_item(i, "EMPTY") == true) {
        i++;
    }

    return output_array;
}
