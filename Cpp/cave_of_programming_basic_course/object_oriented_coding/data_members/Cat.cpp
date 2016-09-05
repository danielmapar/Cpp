#include <iostream>
#include "Cat.h"

using namespace std;

void Cat::speak() {
    if (happy) {
        cout << "Meouw!!!" << endl;
    } else {
        cout << "Sssss!!!" << endl;
    }
}

void Cat::makeHappy() {
    happy = true;
}

void Cat::makeSad() {
    happy = false;
}