//
//  Inhetirance.cpp
//
//
//  Created by Daniel Marchena on 2015-09-28.
//
//

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Person {

private:
    string name;
    string idNum;
protected:
    string prefix;
public:
    Person(const string &name, const string &idNum);
    // dynamic binding to determine which destructor to execute
    virtual ~Person();
    string getName();
    friend ostream& operator<<(ostream& ostream, const Person &person);
    // dynamic binding
    // When calling Student:print, it will call Person:print (static binding),
    // but if we do dynamic binding it will call Student:print
    // page 100 for more information
    // dynamic binding does a run-time decision, besides the static
    // that only considers the variable type (the source code)

    // There is no such thing as a virtual constructor.
    // Such a concept does not make any sense. Virtual
    // destructors, however, are very important. In our array
    // example, since we store objects of both types Person
    // and Student in the array, it is important that the
    // appropriate destructor be called for each object.

    virtual void print();
};

Person::~Person() {
    cout << "Person delete" << endl;
}

Person::Person(const string &name, const string &idNum) {
    this->prefix = "Mr";
    this->name = name;
    this->idNum = idNum;
}

ostream& operator<<(ostream& out, const Person &person){
    out << person.name << "  " << person.idNum << endl;
    return out;
}

void Person::print() {
    cout << name << endl;
    cout << idNum << endl;
}

string Person::getName() {
    cout << name << endl;
    return name;
}

class Student : public Person {

private:
    string major;
    string gradYear;
public:
    Student(const string &name, const string &idNum, const string &major);
    ~Student();
    // dynamic binding
    void print();
    void changeMajor(const string &newMajor) ;
};

Student::~Student() {
    cout << "Student delete" << endl;
}

Student::Student(const string &name, const string &idNum, const string &major) : Person(name, idNum){
    this->major = major;
}

void Student::changeMajor(const string &newMajor) {
    major = newMajor;
}

void Student::print(){
    Person::print();
    cout << prefix << " " << major << endl;
}

int main(void) {

    Person person = Person("Daniel", "123");
    //person.print();
    //cout << person;

    Student student = Student("Daniel", "123", "CS");
    //student.print();

    //Student *student2 = new Student("Pedro", "456", "ADM");

    //Person *pp[20];
    //pp[0] = new Person("Daniel", "123");
    Person *ppp = new Student("Pedro", "456", "ADM");
    ppp->print();

    delete ppp;

    cout << "END" << endl;

    // static binding vs dynamic binding
    //pp[0]->print();
    //pp[1]->print();
    return 0;
}
