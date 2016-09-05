#include <iostream>
#include <sstream>
#include "Person.h"

using namespace std;

string Person::toString() {
    stringstream ss;
    ss << "Person name is: " << name << " and age: " << age;
    return ss.str();
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
    age = 10;
}

Person::~Person() {
    cout << "Person destroyed." << endl;
}