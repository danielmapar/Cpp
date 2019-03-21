#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// READ THIS: https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html

class Test {
private:
    static const int SIZE=100;
    int *_pBuffer;
    
public:
    Test() {
        cout << "Constructor" << endl;
        _pBuffer = new int[SIZE]();
    }
    
    Test(int i) {
        cout << "Parameterized constructor" << endl;
        
        _pBuffer = new int[SIZE]{}; // the ()/{} set everything to 0
        // Also can use memset or fill
        // fill(_pBuffer, _pBuffer+SIZE, 0);
        
        for(int i = 0; i < SIZE; i++) {
            _pBuffer[i] = 7*i;
        }
    }
    
    Test(const Test &other) {
        cout << "Copy constructor" << endl;
        
        this->_pBuffer = new int[SIZE]{};
        copy(_pBuffer, _pBuffer + SIZE, other._pBuffer);
        //memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
        
    }
    
    Test &operator=(const Test &other) {
        cout << "Assignment" << endl;
        
        delete [] _pBuffer;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        
        return *this;
    }
    
    virtual ~Test() {
        cout << "Destructor" << endl;
        
        delete [] _pBuffer;
    }
    
    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hello from test";
    return out;
}


Test getTest() {
    // Call the constructor
    return Test();
}

int main() {
    
    Test test1 = getTest();
    
    cout << test1 << endl;
    
    vector<Test> vec;
    vec.push_back(Test());
    
    
    /*
     Every C++ expression is either an lvalue or an rvalue. An lvalue refers to an object that persists beyond a single expression. You can think of an lvalue as an object that has a name. All variables, including nonmodifiable (const) variables, are lvalues. An rvalue is a temporary value that does not persist beyond the expression that uses it.
     
     // lvalues_and_rvalues1.cpp
     // compile with: /EHsc
     #include <iostream>
     using namespace std;
     int main()
     {
         int x = 3 + 4;
         cout << x << endl;
     }
    In this example, x is an lvalue because it persists beyond the expression that defines it. The expression 3 + 4 is an rvalue because it evaluates to a temporary value that does not persist beyond the expression that defines it.
     
     */
    
    // value is an L value
    // 7 is a R value
    int value1 = 7;
    
    int *pValue1 = &value1;
    // 7 is an R value
    // int *pValue2 = &7;
    
    Test *pTest1 = &test1;
    // getTest returns a temporary value (R value)
    //Test *pTest2 = &getTest();
    
    int *pValue3 = &++value1;
    cout << *pValue3 << endl;
    
    // Not gonna work. Because the post ++ will create a copy for you
    // The copy will be used to get the address (&value1), but the original one will be incremented
    // Remember: An rvalue is a temporary value that does not persist beyond the expression that uses it.
    //int *pValue3 = &value1++;
    //cout << *pValue3 << endl;
    
    // You cant, because (7 + value1) is an R value (temporary variable)
    // Having said that, you wont be able to get the address of a temporary value
    // int *s = &(7 + value1);
    
    return 0;
    
}
