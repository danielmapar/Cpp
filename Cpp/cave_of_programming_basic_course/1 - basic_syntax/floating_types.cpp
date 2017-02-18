#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float fValue = 76.4;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of long double: " << sizeof(long double) << endl;
    cout << fixed << fValue << endl;
    cout << scientific << fValue << endl; // 10 to the power of 1
    // cout outputs 8 significant digits by default
    cout << setprecision(20) << fixed << fValue << endl;

    // no signed/unsigned for double and float
    double dValue = 76.4;
    // 17 precise digits (including the .)
    cout << setprecision(20) << fixed << dValue << endl;

    long double ldValue = 76.4;
    cout << setprecision(20) << fixed << ldValue << endl;

    return 0;
}