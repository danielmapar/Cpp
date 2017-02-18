#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
    return Test();
}

int main() {
    
    int i, j;
    // Correct usage: the conditional operator returns an lvalue.
    ((i < 3) ? i : j) = 7;
    
    Test test1 = getTest();
    
    cout << test1 << endl;
    
    vector<Test> vec;
    vec.push_back(Test());
    
    Test &rTest1 = test1;
    
    // The return values of functions are R values
    //Test &rTest2 = getTest();
    
    // We can make it work by using const
    // Because const L value references can actually bind to R values
    // This means that as long as this reference exists:
    // const Test &rTest2
    // the object returned by getTest() will exist as well
    const Test &rTest2 = getTest();

    return 0;
    
}
