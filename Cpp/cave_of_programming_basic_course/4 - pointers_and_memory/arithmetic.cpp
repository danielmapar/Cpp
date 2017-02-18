#include <iostream>

using namespace std;

int main(void) {

    // C++ will discart the floating point part
    double value = 7/3;
    cout << value << endl;

    // C++ will maintain the decimals if one of the numbers is actually a floating
    double value2 = 7.0/3;
    cout << value2 << endl;

    // or

    double value3 = double(7)/3;
    cout << value3 << endl;

    return 0;
}