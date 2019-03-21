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


/*
 class A
 {
 public:
 int x;
 protected:
 int y;
 private:
 int z;
 };
 
 class B : public A
 {
 // x is public
 // y is protected
 // z is not accessible from B
 };
 
 class C : protected A
 {
 // x is protected
 // y is protected
 // z is not accessible from C
 };
 
 class D : private A    // 'private' is default for classes
 {
 // x is private
 // y is private
 // z is not accessible from D
 };

 
 class Base {
 public:
 int publicMember;
 protected:
 int protectedMember;
 private:
 int privateMember;
 };
 
 Everything that is aware of Base is also aware that Base contains publicMember.
 Only the children (and their children) are aware that Base contains protectedMember.
 No one but Base is aware of privateMember.
 */
