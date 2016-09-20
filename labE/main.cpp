#include <cmath>
#include <random>
#include <iostream>
#include <stdio.h>

using namespace std;

char get_random_char();

// Initialize given constants,
char chararr[10] = {'a', 'b', 'c', 'd', 'E', 'F', '!', '*', '6', '2'};
const int pass_min_len = 1;
const int pass_max_len = 25;

int main(int argc, char** argv)
{
    int seed, pass_length;
    char user_continue;
    string generated_password;
    
    // Seed the random with input:
    cout << "Enter seed: ";
    cin >> seed;
    srand(seed);
    
    // Get desired password length:
    cout << "Enter password length: ";
    cin >> pass_length;
    
    if (pass_length > pass_max_len) {
        pass_length = pass_max_len;
    } else if (pass_length < pass_min_len) {
        pass_length = pass_min_len;
    }
    
    // Prompt user that password is OK.
    do {
        generated_password = "";
        for (int i = 0; i < pass_length; i++) {
            generated_password += get_random_char();
        }
        
        // Ask for confirmation
        cout << generated_password << endl;
        cout << "Accept password? ";
        cin >> user_continue;
        
        // Repeat if needed.
    } while (user_continue != 'y' && user_continue != 'Y');
    
}

// Returns a single random character from the chararr array.
char get_random_char() {
    int randgen;
    
    randgen = (rand() % (10));
    
    return chararr[randgen];
}