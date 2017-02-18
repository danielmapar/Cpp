#include <iostream>
#include <exception>

using namespace std;

/*
 const means that this function (which is a member function) will not change the observable state of the object it is called on. The compiler enforces this by not allowing you to call non-const methods from this one, and by not allowing you to modify the values of members.
 throw() means that you promise to the compiler that this function will never allow an exception to be emitted. This is called an exception specification, and (long story short) is useless and possibly misleading.
 */

class MyException: public exception {

public:
    // throw() --> wont accept any exception
    // throw(excp2, excp3) --> enables some exceptions
    virtual const char *what() const throw() {
        return "Something bad happened.";
    }
};

class Test {

public:
    /* 
     libc++abi.dylib: terminating with unexpected exception of type MyException: Something bad happened.
     Abort trap: 6
     
    void goesWront() throw() {
        throw MyException();
    }
     However, this is fine:
     void goesWront() throw(MyException) {
        throw MyException();
     }
     
     no compile time checking on throw(...)
     
     */
    void goesWront() {
        throw MyException();
    }
    
};

int main(void) {

    try {
        Test test;
        test.goesWront();
    } catch(MyException &e) {
        cout << e.what() << endl;
    }
    
    return 0;
}