#include <iostream>

using namespace std;

class Animal {
public:
    void speak() { cout << "Grr" << endl; };
};

class Cat : public Animal {
public:
    void jump() { cout << "Cat jumping" << endl; };
};

class Tiger : public Cat {
public:
    void attack() { cout << "Attack!!!" << endl; };
};

int main(void) {
    
    Animal animal;
    animal.speak();
    
    Cat cat;
    cat.speak();
    cat.jump();
    
    Tiger tiger;
    tiger.speak();
    tiger.jump();
    tiger.attack();

    return 0;
}