#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int nextTemp;
    char season;

    ifstream fin;
    fin.open("testdat.dat");

    while (fin >> nextTemp >> season) {
        cout << "The temp is " << nextTemp << " and season " << season << endl;
    }

    fin.close();
    return 0;
}
