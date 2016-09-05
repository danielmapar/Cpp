#include <iostream>
#include "Cat.h"

using namespace std;

int main(void) {
    cout << "Start" << endl;
    // Variable gets destroyed after this scope is done
    {
        Cat jim;
        jim.speak();
    }
    cout << "End" << endl;
    return 0;
}