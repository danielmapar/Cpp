#include <iostream>
#include <limits>

using std::cout;
using std::endl;

int main(void) {

    cout << "Max int value: " << INT_MAX << endl;
    cout << "Min int value: " << INT_MIN << endl; 
    // sizeof is an operator -- size in bytes 
    cout << sizeof(int) << endl;
    cout << sizeof(short int) << endl;
    cout << sizeof(unsigned int) << endl;
    cout << sizeof(signed int) << endl;



    return 0;
}