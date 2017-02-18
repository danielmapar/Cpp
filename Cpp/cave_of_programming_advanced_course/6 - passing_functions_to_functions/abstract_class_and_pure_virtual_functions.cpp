#include <iostream>

using namespace std;

// pure virtual methods => virtual func(int a)=0
// abstract class
class Animal {
public:
    // pure virtual function
    virtual void speak()=0;
    virtual void run()=0;
};

// this is abstract as well, since it does not provide
// an implementation for run()
class Dog: public Animal {
private:
    string d;
public:
    virtual void speak() {
        d = "Dog";
        cout << d << " Woof!" << endl;
    }
};


class Labrador: public Dog {
public:
    virtual void run() {
        cout << "Run!" << endl;
    }
};

void test(Animal &a) {
    a.run();
}

int main(void) {
    // Can't do
    // Animal animal;
    // animal.speak();
    
    // Dog dog;
    // dog.speak();
    
    Labrador labrador;
    labrador.speak();
    labrador.run();
    
    // We cant do: Animal animals[10];
    // Because that would trigger a constructor, but
    // Animal is an abstract class and does not have one
    
    // but we can make an array of pointers
    Animal *animal[5];
    *(animal+0) = &labrador;
    
    animal[0]->run();
    
    test(*animal[0]);
    
    return 0;
}