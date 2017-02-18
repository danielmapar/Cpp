#include <iostream>
#include "ring.hpp"

using namespace std;

int main(void) {
    
    ring<string> textstring(3);
    
    textstring.add("one");
    textstring.add("two");
    textstring.add("three");
    textstring.add("four");
    
    for (ring<string>::iterator it = textstring.begin(); it != textstring.end(); it++) {
        cout << *it << endl;
    }
    
    cout << "---------" << endl;
    
    for (string text: textstring) {
        cout << text << endl;
    }
    
    return 0;
}