#include <iostream>

using namespace std;

class Animal {
private:
    string name;
public:
    Animal() { cout << "Animal created" << endl; };
    // copy constructor (copy properties from one object to the other)
    Animal(const Animal& other) : name(other.name) {
        //name = other.name;
        // Cant call speak() if I dont guarantee to the compiler that
        // this function wont change any of the "const Animal& other" properties. Having said that, we use the keyword const on the method speak to enforce that. the "other" variable is a reference,
        // so it should not be modified
        //other.speak();
        cout << "Animal created by copying." << endl;
    };
    void setName(string name) { this->name = name; };
    void speak() const { cout << "My name is: " << name << endl; };
};

int main(void) {

    Animal animal1;
    
    animal1.setName("Freddy");
    
    // the operator equals in this case invokes the copy constuctor
    Animal animal2 = animal1;
    // we can also call the copy constructor by doing
    Animal animal3(animal2);
    
    animal2.speak();
    animal2.setName("Bob");
    
    animal1.speak();
    animal2.speak();
    
    return 0;
}