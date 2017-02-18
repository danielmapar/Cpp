#include <iostream>

using namespace std;

class Parent {
    
    int dogs{5};
    string text{"hello"};
    
public:
    // You can make one constructor call another (same class) in C++11
    Parent(): Parent("hello") {
        cout << "No parameter parent constructor" << endl;
    }
    Parent(string text) {
        this->text = text;
        cout << "String parent constructor" << endl;
    }
};

class Child : public Parent {
public:
    // Child() {}
    Child() = default;
};

int main(void) {
    Parent parent("Hello");
    Child child;
    
    return 0;
}
