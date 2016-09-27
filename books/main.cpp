#include <iostream>
#include <stdio.h>

using namespace std;

char bookType(int element);

int main(int argc, char** argv)
{
    double cost_books[5] = { 12.00, 7.00, 10.00, 0.60, 0.50 };
    char selling_book, book;
    double total_cost = 0.0;
    int take_book = 0;
    cin >> selling_book;
    for(int i = 0; i < 5; i++) {
        book = bookType(i);
        if(selling_book == book) {
            total_cost += cost_books[i];
            take_book += 1;
        }
    }

    if(take_book != 1) {
        cout << "we do not take that type of book" << endl;
    }
}

char bookType(int element)
{
    char type_books[5] = { 'b', 's', 'm', 'd', 'c' };
    return type_books[element];
}