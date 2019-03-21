#include <iostream>
#include "Cat.h"

using namespace std;

int main(void) {
    Cat jim;
    jim.makeHappy();
    jim.speak();

    Cat bob;
    jim.makeSad();
    bob.speak();
    
    cout << bob.happy << endl;
    
    Cat dan;
    dan.speak();
    
    cout << dan.happy << endl;

    return 0;
}
