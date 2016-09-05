//
//  cast.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-28.
//
//

#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

class Person {
private:
    string name;
public:
    void setName(const string &newName);
    Person();
    virtual ~Person();
};

Person::Person() : name("default") {
    cout << "Construct Person" << endl;
}

void Person::setName(const string &newName) {
    name = newName;
}

Person::~Person() {
    cout << "Destroy person" << endl;
}

class Student : public Person {
private:
    string lastName;
public:
    void setLastName(const string &newLastName);
    Student();
    virtual ~Student();
};

void Student::setLastName(const string &newLastName) {
    lastName = newLastName;
}

Student::Student() : Person(), lastName("default") {
    cout << "Construct Student" << endl;
}

Student::~Student() {
    cout << "Destroy Student" << endl;
    cout << lastName << endl;
}

int main(void) {

    Person *per = new Person;
    Person *stud = new Student;
    
    Student *newStud = dynamic_cast<Student*>(stud);
    
    if (newStud != NULL) {
        newStud->setLastName("new last name");
    }
    
    delete per;
    delete stud;
    
    
    return 0;
}