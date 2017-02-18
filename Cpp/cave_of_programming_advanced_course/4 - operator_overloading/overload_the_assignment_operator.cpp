#include <iostream>

using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(): id(0), name("") {}
    Test(int id, string name): id(id), name(name) {}
    void print() {
        cout << id << ": " << name << endl;
    }
    
    // http://stackoverflow.com/questions/19090023/return-type-of-assignment-operator?lq=1
    Test& operator=(const Test &test) {
        
        cout << "Assignment running" << endl;
        
        this->id = test.id;
        this->name = test.name;
        
        return *this;
    }
    // copy constructor
    // the copy constructor can invoke the assignment operator
    // whenever we have those 2 methods, we probably should have a destructor.
    // the destructor would be used to clean allocated memory (pointers)... since you are implementing those 2 methods, you are probably not dealling with a shallow copy of pointers.
    Test(const Test& test) {
        cout << "Copy initialization" << endl;
        
        // the copy constructor can invoke the assignment operator
        *this = test;
    }
};

int main(void) {
    
    Test test1(10, "Mike");
    test1.print();
    
    Test test2(20, "Bob");
    
    test2 = test1;
    test2.print();
    
    Test test3;
    // That is wht the operator returns a reference of the object
    //test3 = test2 = test1;
    
    test3.operator=(test2);
    test3.print();
    
    cout << "----------" << endl;
    
    // invokes the copy constructor
    Test test4 = test1;
    test4.print();
    
    return 0;
}