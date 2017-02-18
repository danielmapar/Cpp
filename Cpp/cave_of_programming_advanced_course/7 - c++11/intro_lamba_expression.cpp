#include <iostream>

using namespace std;

void callLambda(void (*func)()) {
    func();
}


void complicated(int a) {
    
}

int main() {
    
    // Lamba expression is present in C++11
    // starts with brackets
    // this is like an anonymous function
    auto func = [](){
        cout << "Test" << endl;
    };
    
    func();
    
    // Self initialized lamba expression
    [](){
        cout << "Test 2" << endl;
    }();
    
    callLambda(func);
    
    callLambda([](){
        cout << "Test 4" << endl;
    });
    
    return 0;
}
