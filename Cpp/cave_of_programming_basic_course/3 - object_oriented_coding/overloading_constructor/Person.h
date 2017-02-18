#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person();
    Person(string name) : name(name) { };
    Person(string name, int age) : name(name), age(age) { };
    ~Person();
    string toString();
    void setName(string name);
    string getName();
};

#endif