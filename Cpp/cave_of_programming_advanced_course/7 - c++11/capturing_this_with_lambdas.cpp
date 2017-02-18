#include <iostream>

using namespace std;

class Test {
private:
    int a{1};
    int b{2};
    
public:
    void run() {
        int c{3};
        int d{4};
        
        // you can pass this as part of the scope of the
        // anonymous function
        // this is passed by reference (it is a pointer)
        auto pLambda = [this, c, d](){
            cout << a << b << c << d << endl;
        };
        pLambda();
    }
};

int main(void) {
    Test test;
    test.run();
    return 0;
}
