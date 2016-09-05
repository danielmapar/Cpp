//
//  cast.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-20.
//
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void) {
    
    int cat = 10;
    double dog = (double)cat; // traditional C-style cast
    double pig = double(cat); // C++ functional cast
    
    /*
     Static casting is used when a conversion is made between two related types, for
     example numbers to numbers or pointers to pointers. Its syntax is given below.
     */
    cout << static_cast<int>(dog) << endl;
    
    char command;
    cin >> command;
    switch (command) {
        case 'I':
            cout << "I value";
            break;
        case 'D':
            cout << "D value";
            break;
        default:
            cout << "Default";
            break;
    }
    
    return 0;
}
