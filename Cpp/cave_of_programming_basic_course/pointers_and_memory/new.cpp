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

int main(void) {
    
    Animal cat;
    cat.setName("Freddy");
    cat.speak();

    Animal* dog = new Animal;
    //Animal* dog = new Animal();
    dog->setName("Freddy");
    dog->speak();
    delete dog;
    
    Animal *duck = nullptr;
    delete duck;
    
    // 8 bytes, just like a long
    cout << sizeof(dog) << endl;
    
    //long int ptr =  long(dog);
    // we also have dynamic_case, static_cast, const_cast
    long int ptr = reinterpret_cast<long int>(dog);
    cout << ptr << endl;
    
    
    return 0;
}