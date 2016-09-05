#include <iostream>

using namespace std;

class Animal {
private:
    string name;
public:
    Animal(string name) : name(name) { cout << "Construct Animal" << endl; };
    Animal() { cout << "Construct Animal" << endl; };
    void speak() { cout << "My name is: " << name << endl; };
};

class Cat : public Animal {
public:
    // Always call the default parent constructor
    Cat(string name) : Animal(name) { cout << "Construct Cat" << endl; };
    Cat() { cout << "Construct Cat" << endl; };
    void jump() { cout << "Cat jumping" << endl; };
};

class Tiger : public Cat {
public:
    // Always call the default parent constructor
    Tiger(string name) : Cat(name) { cout << "Construct Tiget" << endl;  };
    Tiger() { cout << "Construct Tiget" << endl; };
    void attack() { cout << "Tiget attack" << endl; };
};

int main(void) {
    
    Tiger tiger("John");
    tiger.speak();
    tiger.jump();
    
    return 0;
}