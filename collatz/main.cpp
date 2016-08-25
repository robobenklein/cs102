#include <iostream>
#include <stdio.h>

unsigned long long modify(unsigned long long original)
{
    if(original == 1) {
        return 1;
    } else if((original % 2) == 0) {
        // Number is even.
        return original / 2;
    } else if((original % 2) == 1) {
        // Number is Odd
        original = (original * 3) + 1;
        return original;
    } else {
        printf("Error: Something bad happened!");
        std::cout << std::endl << "The current number is: " << original;
        std::cout << std::endl << "Mod 2, it returns: " << (original % 2);
    }
    return 1;
}

unsigned long long steps_until_1(unsigned long long begin)
{
    unsigned long long current, steps;
    current = begin;
    steps = 0;
    while(current != 1) {
        steps = steps + 1;
        current = modify(current);
    }
    return steps;
}

unsigned long long longest_chain_until(unsigned long long ending_point)
{
    unsigned long long x, seq_length, maximum = 0, locator;

    printf("Longest Collatz sequence in one to your number... \n");

    for(x = 2; x <= ending_point; x++) {
        //std::cout << "Trying " << x << " to look for a longer chain..." << std::endl;
        seq_length = steps_until_1(x);
        if(seq_length > maximum) {
            maximum = seq_length;
            locator = x;
            std::cout << "Found longer chain at " << x << " which is " << seq_length << " steps long." << std::endl;
        }
    }

    return locator;
}

int main(int argc, char** argv)
{
    char solver_choice;
    std::cout << "Solve a number or a sequence? [n/s]: ";
    std::cin >> solver_choice;

    if(solver_choice == 's') {
        unsigned long long begin;
        std::cout << "Test numbers from 2 until what? : ";
        std::cin >> begin;
        std::cout << std::endl << "Best chain: " << longest_chain_until(begin) << std::endl;
    } else if(solver_choice == 'n') {
        unsigned long long begin;
        std::cout << "Enter the number to test: ";
        std::cin >> begin;
        std::cout << std::endl << "Output: " << steps_until_1(begin) << std::endl;
    }

    return 0;
}