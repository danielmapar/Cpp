#include <iostream>

using namespace std;

int main(void) {

    int option = 0;
    cin >> option;

    switch(option) {
        case 1:
            cout << "This is one" << endl;
            break;
        case 2: 
            cout << "This is two" << endl;
            break;
        default: 
            cout << "Ops!!!" << endl;
            break;
    }
    // if you forget to break it will execute all cases and default:
    // This is one                                                                                   
    // This is two                                                                                   
    // Ops!!! 
    return 0;
}