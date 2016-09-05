//
//  friend.cpp
//
//
//  Created by Daniel Marchena on 2015-09-22.
//
//

#include <iostream>

using std::ostream;
using std::cout;

class SomeClass {
    private:
        int secret;
    public:
        SomeClass(int x);
        // Enable this function to access private data
        friend ostream& operator<<(ostream& out, SomeClass& x);

};

SomeClass::SomeClass(int x) {
    secret = x;
}

ostream& operator<<(ostream& out, const SomeClass& x) {
    out << x.secret;
    return out;
}

int main(void) {

    SomeClass x = SomeClass(10);

    cout << x << x;

    return 0;
}
