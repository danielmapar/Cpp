#include <iostream>
#include "Person.h"

using namespace std;

string Person::toString() {
    return "Person is: " + name;
}

void Person::setName(string name) {
    this->name = name;
}

string Person::getName() {
    return name;
}

Person::Person() {
    cout << "Person created." << endl;
    name = "Jorge";
}

Person::~Person() {
    cout << "Person destroyed." << endl;
}