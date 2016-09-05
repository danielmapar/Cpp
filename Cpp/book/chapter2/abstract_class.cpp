//
//  Abstract_class.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-28.
//
//
#include <iostream>

using std::cout;
using std::endl;

// prototype

template <typename T>
T sum(T a, T b);

/*
namespace test {
    int a = 10;
}

using test::a;
 */

// Pure interface
class MyInterface {
public:
    virtual int sum(int a, int b) =0;
    virtual int sub(int a, int b) =0;
};

// With one pure virtual method, we are not allowed to
// create an instance of this object
class MyAbstract {
public:
    // pure virtual method
    virtual int sum(int b, int a) =0;
    int sub(int a, int b);
};

int MyAbstract::sub(int a, int b) {
    return a - b;
}

class First : public MyAbstract {
public:
    int sum(int b, int a);
    
};

int First::sum(int b, int a) {
    return b + a;
}

class Second : public MyInterface {
public:
    int sum(int a, int b);
    int sub(int a, int b);
};

int Second::sum(int a, int b) {
    return a + b;
}

int Second::sub(int a, int b) {
    return a - b;
}

template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main(void) {
    
    //cout << a << endl;
    
    //MyAbstract abs;
    
    cout << sum(5.2, 1.3) << endl;
    
    First obj;
    cout << obj.sum(1,3) << endl;
    cout << obj.sub(1,1) << endl;
    
    Second obj2;
    cout << obj2.sum(2,2) << endl;
    cout << obj2.sub(2,2) << endl;
    
    return 0;
}