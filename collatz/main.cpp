#include <chrono>
#include <iostream>
#include <thread>

struct collatz_upair {
    unsigned long long locator;
    unsigned long long chain;
};

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
        // This was happenning when the number became negative.
        // Accidentally converted unlonglong to an int32
        printf("Error: Something bad happened!");
        std::cout << std::endl << "The current number is: " << original;
        std::cout << std::endl << "Mod 2, it returns: " << (original % 2);
    }
    return 1;
}

// Counts how many steps it takes for the number to reach 1, returns number of steps.
// In and Out are unlonglong numbers.
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

// Looks for the longest chain in the range 2 -> ending_point
// Returns the number with the longest output chain.
unsigned long long longest_chain_until(unsigned long long ending_point)
{
    unsigned long long x, seq_length, maximum = 0, locator;

    printf("Longest Collatz sequence in one to your number... \n");

    for(x = 2; x <= ending_point; x++) {
        // std::cout << "Trying " << x << " to look for a longer chain..." << std::endl;
        seq_length = steps_until_1(x);
        if(seq_length > maximum) {
            maximum = seq_length;
            locator = x;
            std::cout << "Found longer chain at " << x << " which is " << seq_length << " steps long." << std::endl;
        }
    }

    return locator;
}

// Returns a pair, locator, chain, of longest seq it finds.
collatz_upair
evaluate_numbers_mod_num(unsigned long long ending_point, unsigned long long begin, unsigned long long skip, collatz_upair* output_array)
{
    unsigned long long x = 0, seq_length = 0, maximum = 0, locator = 0;

    std::string threadname = "[Thread " + std::to_string(int(begin - 2)) + "]";

//    std::stringstream beginmsg << threadname << "New thread, Begin: " << begin << " Skip: " << skip << std::endl;
//    std::cout << beginmsg;

    for(x = begin; x <= ending_point; x += skip) {
        seq_length = steps_until_1(x);
        if(seq_length > maximum) {
            maximum = seq_length;
            locator = x;
            std::cout << threadname << "Found longer chain at " << x << " which is " << seq_length << " steps long."
                      << std::endl;
        }
    }

    collatz_upair outputpair;
    std::cout << threadname << " [RESULT] Storing pair: " << locator << ", " << maximum << std::endl;
    outputpair.locator = locator;
    outputpair.chain = maximum;
    
    output_array[begin - 2] = outputpair;

    // Number that produced the best result.
    return outputpair;
}

unsigned long long longest_chain_until_threaded(int threadcount, unsigned long long ending_point)
{
    // unsigned long long locator = 0;
    int threadid = 0;

    std::cout << "Longest Collatz sequence in one to " << ending_point << " using " << threadcount << " threads... \n";

    std::thread threads[threadcount];

    collatz_upair threads_output[threadcount];

    for(threadid = 0; threadid < threadcount; threadid++) {
        collatz_upair empty;
        empty.locator = 0;
        empty.chain = 0;
        threads_output[threadid] = empty;
    }

    for(threadid = 0; threadid < threadcount; threadid++) {
        std::cout << std::endl << "Creating thread: " << threadid << std::endl;
        threads[threadid] = std::thread(
            [&] {evaluate_numbers_mod_num(ending_point, (threadid + 2), threadcount, threads_output); });
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    for(threadid = 0; threadid < threadcount; threadid++) {
        threads[threadid].join();
        std::cout << std::endl << "Joined thread " << threadid << std::endl;
    }

    std::cout << "All threads joined.";

    for(int threadid = 0; threadid < threadcount; threadid++) {
        std::cout << std::endl << threads_output[threadid].chain;
    }

    return 0;
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
    } else if(solver_choice == 't') {
        unsigned long long begin;
        int threadcount;
        std::cout << "Enter the number of threads, then the number to test to: ";
        std::cin >> threadcount >> begin;
        std::cout << std::endl << "Output: " << longest_chain_until_threaded(threadcount, begin) << std::endl;
    }

    return 0;
}
