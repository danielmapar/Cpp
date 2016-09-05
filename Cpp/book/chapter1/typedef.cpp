//
//  typedef
//
//
//  Created by Daniel Marchena on 2015-09-18.
//
//

#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

namespace myglobals {
    int cat = 1;
    string dog = "bow wow";
}

//using namespace myglobals;
using myglobals::dog;

int main() {

    typedef char *BufferPtr;
    typedef char Byte;
    typedef double Coordinates;

    BufferPtr p = new Byte;
    *p = 'A';
    Coordinates x, y;
    x = 1.0;

    const int Cat = 1;

    cout << *p << endl;
    cout << x << endl;

    cout << myglobals::cat << dog << endl;

    delete p;

    return EXIT_SUCCESS;
}
