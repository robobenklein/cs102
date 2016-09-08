#include <chrono>
#include <iostream>
#include <sstream>
#include <thread>

struct collatz_upair {
    unsigned long long locator;
    unsigned long long chain;
};

class collatz_solver
{
    // Max and location of the max, desired as output.
    unsigned long long max_chain = 0, max_locator = 0;

    unsigned long long ending_point, begin, skip;

    std::string threadname;

    collatz_upair outputpair;

    // Used in loops, not kept.
    unsigned long long x, seq_length;

    bool finished = false;

public:
    collatz_solver()
    {
        outputpair.locator = 0;
        outputpair.chain = 0;

        ending_point = 2;
        begin = 1;
        skip = 1;

        threadname = "[New Solver]";
        std::cout << threadname << " Default Initialized, Begin: " << begin << " Skip: " << skip
                  << " End: " << ending_point << std::endl;
    }

public:
    collatz_solver(unsigned long long ending_point, unsigned long long begin, unsigned long long skip)
    {
        threadname = ("[Thread " + std::to_string(int(begin - 2)) + "]");
        outputpair.locator = 0;
        outputpair.chain = 0;

        ending_point = ending_point;
        begin = begin;
        skip = skip;
    }

public:
    void init(unsigned long long ending_point, unsigned long long begin, unsigned long long skip)
    {
        this->threadname = ("[Thread " + std::to_string(int(begin - 2)) + "]");
        std::cout << threadname << " Init called, Begin: " << begin << " Skip: " << skip << " End: " << ending_point
                  << std::endl;

        this->max_locator = 0;
        this->outputpair.locator = 0;
        this->max_chain = 0;
        this->outputpair.chain = 0;

        this->ending_point = ending_point;
        this->begin = begin;
        this->skip = skip;
    }

public:
    collatz_upair run()
    {
        this->outputpair = this->calculate();
        std::cout << this->max_locator << " | " << this->max_chain << std::endl;
        // this->outputpair.locator = this->max_locator;
        // this->outputpair.chain = this->max_chain;
        this->finished = true;
        return outputpair;
    }

public:
    collatz_upair result()
    {
        return this->outputpair;
    }

    // Used as one 'step' of the chain.
    unsigned long long modify(unsigned long long original)
    {
        if(original == 1 || original == 0) {
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
    unsigned long long steps_until_1(unsigned long long number)
    {
        unsigned long long current, steps;
        current = number;
        steps = 0;
        while(current != 1 && current != 0) {
            steps = steps + 1;
            current = modify(current);
        }
        return steps;
    }

    // Returns a pair, locator, chain, of longest seq it finds.
private:
    collatz_upair calculate()
    {
        this->max_chain = 0;
        this->max_locator = 0;
        this->seq_length = 0;

        for(unsigned long long x = this->begin; x <= this->ending_point; x += this->skip) {
            this->seq_length = this->steps_until_1(x);
            if(this->seq_length > this->max_chain) {
                this->max_chain = this->seq_length;
                this->max_locator = x;
            }
        }

        //        std::cout << this->threadname << " [RESULT] Storing pair: " << this->max_locator << ", " <<
        //        this->max_chain
        //                  << std::endl;
        this->outputpair.locator = this->max_locator;
        this->outputpair.chain = this->max_chain;

        // Number that produced the best result.
        return outputpair;
    }
};
// End class collatz_solver

// Creates a new solver for each thread and starts them.
unsigned long long longest_chain_until_threaded(int threadcount, unsigned long long ending_point)
{
    int threadid = 0;

    std::cout << "Longest Collatz sequence in one to " << ending_point << " using " << threadcount << " threads... \n";

    collatz_solver solvers[threadcount];
    std::thread threads[threadcount];

    collatz_upair threads_output[threadcount];

    // Initialize the solvers
    for(threadid = 0; threadid < threadcount; threadid++) {
        //        solvers[threadid] = new collatz_solver();
        solvers[threadid].init(ending_point, (threadid + 2), threadcount);
    }

    // Start the solvers in their own threads.
    for(threadid = 0; threadid < threadcount; threadid++) {
        std::cout << std::endl << "Creating thread: " << threadid << std::endl;
        threads[threadid] =
            std::thread([&] { std::cout << std::to_string(solvers[threadid].run().locator) << std::endl; });
    }

    // Min time until joining threads
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Done creating threads." << std::endl;

    for(threadid = 0; threadid < threadcount; threadid++) {
        threads[threadid].join();
        threads_output[threadid] = solvers[threadid].result();
        std::cout << std::endl << "Joined thread " << threadid << std::endl;
    }

    std::cout << "All threads joined.";

    for(int threadid = 0; threadid < threadcount; threadid++) {
        std::cout << std::endl << threads_output[threadid].chain;
    }

    for(int threadid = 0; threadid < threadcount; threadid++) {
        //        delete solvers;
        //        delete threads;
    }

    return 0;
}

int main(int argc, char** argv)
{
    unsigned long long ending_point, test_point = 0;
    char solver_choice;
    std::cout << "Solve a number or a sequence? [n/s]: ";
    std::cin >> solver_choice;

    collatz_solver default_solver;

    if(solver_choice == 's') {
        std::cout << "Test numbers from 2 until what? : ";
        std::cin >> ending_point;
        default_solver.init(ending_point, 2, 1);
        default_solver.run();
        std::cout << std::endl << "Best chain: " << default_solver.result().locator << std::endl;
    } else if(solver_choice == 'n') {
        std::cout << "Enter the number to test: ";
        std::cin >> test_point;
        default_solver.init(test_point, test_point, 1);
        default_solver.run();
        std::cout << std::endl << "Chain length: " << default_solver.result().chain << std::endl;
    } else if(solver_choice == 't') {
        unsigned long long ending_point;
        int threadcount;
        std::cout << "Enter the number of threads, then the number to test to: ";
        std::cin >> threadcount >> ending_point;
        std::cout << std::endl << "Output: " << longest_chain_until_threaded(threadcount, ending_point) << std::endl;
    }

    return 0;
}
