#include <iostream>

using namespace std;

int main(void) {
    bool bValue = true; // 1 - true, 0 - false
    cout << bValue << endl;

    char cValue = 55;
    char cValue2 = '7';
    cout << cValue << endl; // ASCII - 7
    cout << cValue2 << endl;
    cout << int(cValue2) << endl;

    cout << "Size of char: " << sizeof(char) << endl;

    wchar_t wValue = 'i'; // bigger than a char - 1 byte vs 4 bytes
    cout << wValue << endl;
    cout << "Size of wchar_t: " << sizeof(wValue) << endl;
    return 0;
}