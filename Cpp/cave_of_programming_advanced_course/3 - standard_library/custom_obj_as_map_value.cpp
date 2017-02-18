#include <iostream>
#include <map>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person() {}
    // When you make a custom constructor
    // you lose the automatic empty one Person() {}
    Person(string name, int age) : name(name), age(age) {
    };
    
    Person(const Person &other) {
        cout << "Copy constructor running" << endl;
        name = other.name;
        age = other.age;
    }
    
    void print();
};

void Person::print() {
    cout << "Name: " << name << ", age: " << age << endl;
}

int main(void) {
    
    map<int, Person> people;
    
    // uses the default constructor to construct the obj
    //people[0]
    // = Person
    // will trigger the copy operator afterwards
    
    // shallow copy (will copy pointers - danger)
    people[0] = Person("Daniel", 23);
    people[1] = Person("Jack", 13);
    people[2] = Person("Pedro", 20);
    
    // invokes copy constructor
    people.insert(make_pair(55, Person("Bob", 47)));
    
    for(map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
        it->second.print();
    }

    return 0;
}