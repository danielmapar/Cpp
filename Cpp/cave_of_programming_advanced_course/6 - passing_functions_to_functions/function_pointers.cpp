#include <iostream>

using namespace std;

void test() {
    cout << "Test" << endl;
}

int test2(int a, int b) {
    return a + b;
}

// c++11 - lamba expressions
// An example of function pointers is a
// virtual method, the virtual key word is associated
// if the creation of a VTable, which is a table of function
// pointers. C++ does a lookup on this table and finds the
// right function to call


int main(void) {

    test();
    
    // this does not work, since this can represent
    // a function prototype
    // this function returns a void pointer and has no params
    //void *pTest();
    
    // this is how you make a pointer to a function that
    // return void (not void*) and has an empty parameter
    // list
    void (*pTest)();
    pTest = &test;
    // also works, because the name of a function is in fact a pointer to that function
    pTest = test;
    
    // This is ambiguous, since it looks like we
    // are calling a function that will return something, and we will dereference that value using the *
    //*pTest();
    
    // the right way to do it is:
    (*pTest)();
    // also works, since we have the parameter list ();
    // doing () is like dereferencing the pointer
    pTest();
    
    cout << "---------" << endl;
    
    int (*pTest2)(int, int) = test2;
    // also works
    //int (*pTest2)(int a, int b) = test2;
    
    cout << pTest2(2, 3) << endl;
    
    return 0;
}
