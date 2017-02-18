#include <iostream>

using namespace std;

void getFunc(void (*func)(string name)) {
    func("New");
}

void getFunc2(double (*func)(double a, double b)) {
    cout << func(20.0, 10.0) << endl;
}

int main() {

    auto pGreet = [](string name){ cout << "Hello " << name << endl; };
    
    pGreet(string("Daniel"));
    
    getFunc(pGreet);
    
    // C++ can infer the return type of a lambda expression
    auto pDivide = [](double a, double b){
        return a/b;
    };
    
    cout << pDivide(10.0, 5.0) << endl;
    
    // We can use the trailing return type we saw before being used with auto
    auto pDivide2 = [](double a, double b) -> double{
        if (b == 0.0) {
            return 0;
        }
        return a/b;
    };
    
    cout << pDivide2(10.0, 5.0) << endl;
    
    cout << "-----" << endl;

    getFunc2(pDivide2);
    return 0;
}
