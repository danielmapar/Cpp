#include <iostream>
#include <vector>
using namespace std;

class Test {
public:
    Test() {
        cout << "Constructor" << endl;
    }
    
    Test(int i) {
        cout << "Parameterized constructor" << endl;
    }
    
    Test(const Test &other) {
        cout << "Copy constructor" << endl;
    }
    
    Test &operator=(const Test &other) {
        cout << "Assignment" << endl;
        return *this;
    }
    
    ~Test() {
        cout << "Destructor" << endl;
    }
    
    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hello from test";
    return out;
}

// Elision - the omission of a sound or syllable when speaking
// We are omitting copies and unnecessary objects in this case

// Return value Optimation -> when we run without the -fno-elide-constructors flag
// The compiler can spot those unnecessary copies

// Run without Copy Elision and Optimization - g++ elision_and_optimization.cpp -fno-elide-constructors
// Call the copy constructor
Test getTest() {
    // Call the constructor
    return Test();
}

int main() {
    
    // Call the destructor because of line 39 (out of scope)
    // Call the copy constructor because of line 37
    Test test1 = getTest();
    
    // Destroy object returned on line 37
    
    cout << test1 << endl;
    vector<Test> vec;
    // This will invoke a constructor and a copy constructor (without the -fno-elide-constructors flag). C++ 11 solve this problem with R value references
    vec.push_back(Test());
    
    // Destroy object from line 46
    
    return 0;
    
}
