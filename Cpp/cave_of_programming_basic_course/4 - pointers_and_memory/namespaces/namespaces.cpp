#include <iostream>

#include "Cat.h"
#include "Animals.h"

using namespace std;

int main(void) {
    
    Cat cat;
    cat.speak();
    
    animals::Cat cat2;
    cat2.speak();
    
    cout << animals::CATNAME << endl;
    
    return 0;
}