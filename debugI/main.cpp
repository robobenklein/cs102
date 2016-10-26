#include <fstream>
#include <iostream>
#include <string>
// S: I don't remember what to include for a string stream, but I keep getting
// S: an error!
// A: Included "sstream"
#include <sstream>

using namespace std;

int main()
{
    string input_file;
    string line;
    istringstream sin;
    ifstream fin;

    int i, j, k;

    cout << "Enter input filename: ";
    cin >> input_file;
    cout << endl;

    fin.open(input_file);
    if(fin.fail()) {
        cout << "Unable to open input file.\n";
        return -1;
    }

    while(getline(fin, line)) {
        // S: For some reason, sin gives me the first line with no problems, afterward
        // S: I don't get any more information!
        // A: Remember to clear the old stringstream before adding more into it:
        sin.clear();
        sin.str(line);

        // S: Fields A, B, C are all optional, so I only print out those fields that
        // S: exist in the line, however when I do sin >> i >> j >> k, how do I differentiate those
        // S: fields that got data and those that did not.
        // A: it looks like all you wanted to do was to try getting each one individually, so you can just
        // A: replace the >> j >> k since you already take them in in your later if statements.
        // A: For default values of the vars, use something unique that can't be an input, like -1.
        // A: in this case, you can check if the value is real or not, if it has the default value.
        if(sin >> i /*>> j >> k*/) {
            cout << "Field A = " << i;
            if(sin >> j) {
                cout << ", Field B = " << j;
                if(sin >> k) {
                    cout << ", Field C = " << k;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
