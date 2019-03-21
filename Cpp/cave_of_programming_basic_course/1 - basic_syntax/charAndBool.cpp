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

    cout << "Size of char in bytes: " << sizeof(char) << endl;
    
    // wchar_t is effectively UTF-16 which is 2 bytes wide, but can be 4 bytes (2 characters) if the code is above U+FFFF. 
    wchar_t wValue = 'i'; // bigger than a char - 1 byte vs 4 bytes
    cout << wValue << endl;
    cout << "Size of wchar_t in bytes: " << sizeof(wValue) << endl;
    return 0;
}
