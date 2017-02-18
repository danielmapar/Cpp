#include <iostream>

using namespace std;

class Animal {
private:
    string name;
public:
    Animal() { cout << "Animal created" << endl; };
    
    Animal(const Animal& other) : name(other.name) {
        cout << "Animal created by copying." << endl;
    };
    
    ~Animal() {
        cout << "Destructor called" << endl;
    };
    
    // only constructors take base initializers
    // void setName(string name) : name(name) { };
    void setName(string name) { this->name = name; };
    
    void speak() const { cout << "My name is: " << name << endl; };
};

// The MacOSX compiler is optimized to create the animal object just once and give it to "main".
// However, if we supply this code to another compiler, it could create
// a temporary object first (calling the constructor and destructor inside createAnimalv1)
// and also call the constructor and destructor again inside the main function.
Animal createAnimalv1() {
    Animal animal;
    animal.setName("Bob");
    return animal;
}

// A more optimized way to do it is just use pointers. However, is less safe since you need
// to release the memory afterwards

// C++11 -> g++ -std=c++11 returning_object.cpp
unique_ptr<Animal> createAnimalv2() {
    unique_ptr<Animal> animal(new Animal());
    animal->setName("Bob");
    return animal;
}

Animal* createAnimalv3() {
    Animal* animal = new Animal();
    animal->setName("Bob2");
    return animal;
}

int main(void) {
    
    unique_ptr<Animal> cat = createAnimalv2();
    cat->speak();
    
    Animal* cat2 = createAnimalv3();
    cat2->speak();
    delete cat2;
    
    return 0;
}