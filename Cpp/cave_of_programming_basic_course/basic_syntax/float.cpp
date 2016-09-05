#include <iostream>
#include <iomanip>
using namespace std;

// We can only rely on a float when we define a certain number of digits
// floats and doubles store garbage after some point
// check floating_types.cpp for more

int main(void) {
    float value1 = 1.1;
    float value2 = 1.1;
    cout << "Value1: " << value1 << endl;

    if (value1 == value2) {
        cout << "Vars are equal" << endl;
    }

    // comparing a float/double to a literal can be letal
    // ints are fine
    if (value1 < 1.11) { // if (value1 == 1.1) {
        cout << "equals" << endl;
    } else {
        cout << "not equals" << endl;
    }

    // value1 is actually 1.100000024
    cout << setprecision(10) << value1 << endl;

    return 0;
}