//
//  reference.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-20.
//
//

#include <iostream>
#include <cstdlib>


using std::cout;
using std::endl;
using std::ostream;

struct Passanger {
    std::string name;
    int age;
};

int func(int a, int& b);
void func2(const Passanger& pass);
bool operator==(const Passanger& pass, const Passanger& pass2);
ostream& operator<<(ostream& out, const Passanger& pass);
inline int min(int x, int y) { return (x < y ? x : y); }

int main(void) {
    
    int a = 10, b = 20;
    
    a = func(a, b);
    
    cout << b;
    
    Passanger pass = { "Daniel" , 21 };
    Passanger pass2 = { "Daniel2" , 22 };
    
    func2(pass);
    
    cout << (pass == pass2) << endl;
    
    cout << pass << endl;
    
    cout << pass2 << endl;
    
    cout << min(1, 2) << endl;
    
    return EXIT_SUCCESS;
}

int func(int a, int& b) {
    
    b = 10;
    return a;
}

void func2(const Passanger& pass) {
    cout << pass.name;
    //pass.name = "Error"; // error
}

bool operator==(const Passanger& pass, const Passanger& pass2) {
    return pass.name == pass2.name;
}

ostream& operator<<(ostream& out, const Passanger& pass) {
    out << pass.name << " " << pass.age;
    if (pass.age > 21) {
        out << "Over 21";
    }
    return out;
}
