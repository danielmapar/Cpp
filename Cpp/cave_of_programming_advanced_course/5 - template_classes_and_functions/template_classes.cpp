#include <iostream>

using namespace std;

template <class T, class K, class J>
class Test {
private:
    T obj;
public:
    Test(T obj) : obj(obj) {
        cout << "Construct T" << endl;
    }
    
    void print() {
        cout << obj << endl;
    }
};


int main(void) {
    Test<int, string, float> testInt = 10;
    testInt.print();
    
    Test<string, string, float> testString = string("Test");
    testString.print();
    
    return 0;
}