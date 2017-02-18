#include <iostream>
#include <typeinfo>

using namespace std;

double sum(double a, double b) {
    return a+b;
}

int main() {
    
    string value;
    
    // returns NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
    // this is name mangling
    // the compiler concatenate useful information about
    // the obj in question. ex: is it an overloaded class?
    cout << typeid(value).name() << endl;
    
    // define the variable type based on another variable
    decltype(value) name = "Bob";
    cout << name << endl;
    
    decltype(sum(1, 2)) age = 10.0;
    cout << age << endl;
    
    return 0;
}