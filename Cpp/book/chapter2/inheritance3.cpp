//
//  Inhetirance3.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-28.
//
//

#include <iostream>

class Base {
    
public:
    int bar;
protected:
    int foo;
    
};

class Derive1 : public Base {
    // foo is protected and bar is public
};

class Derive2 : protected Base {
    // foo is protected and bar is protected
};

class Derive3 : private Base {
    //both foo and bar are private
};


int main(void) {

    return 0;
}