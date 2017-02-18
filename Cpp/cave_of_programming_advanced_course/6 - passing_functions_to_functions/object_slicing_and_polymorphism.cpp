#include <iostream>

using namespace std;

class Parent {
private:
    int one;
public:
    Parent(): one(0){
    }
    // creates a table of function pointers
    virtual void print() {
        cout << "parent" << endl;
    }
    // by making this constructor, we lose the implicity ones. ex:  Parent() {}
    Parent(const Parent &other): one(0) {
        one = other.one;
        cout << "copy parent" << endl;
    }
    
    virtual ~Parent() {
        cout << "destroy parent" << endl;
    }
    
};

class Child : public Parent {
private:
    int two;
public:
    Child(): two(2) {
    }
    void print() {
        cout << "child: " << two << endl;
    }
    
    virtual ~Child() {
        cout << "destroy child" << endl;
    }
    
};

int main(void) {

    Child c1;
    // This is a refence and wont trigger a copy constructor
    Parent &p1 = c1;
    p1.print();
    cout << "-------" << endl;
    
    // This is triggers a copy constructor
    Parent p2 = c1;
    p2.print();
    cout << "-------" << endl;
    
    // This will use the virtual lookup table
    Parent *pointer1 = &c1;
    pointer1->print();
    cout << "-------" << endl;
    
    // This is calling the parent class copy constructor
    // we are upcasting a child object to a parent type
    // since this is happening, we lose the parameter two
    // this is called object silicing
    Parent p3 = Child();
    p3.print();
    cout << "-------" << endl;

    
    return 0;
}

//A useful rule is: if there are any virtual methods in a class, it should have a virtual destructor, even if it doesn't do anything.