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
    
    void print() const;
    
    bool operator<(const Person& other) const;
};

void Person::print() const {
    cout << "Name: " << name << ", age: " << age << endl;
}

bool Person::operator<(const Person& other) const {
    // or if (age < other.age) --> no need to use this
    if (this->name == other.name) {
        return this->age < other.age;
    } else {
        return this->name < other.name;
    }
}

int main(void) {
    
    // map only accepts unique keys
    // multi maps accept duplicate keys
    map<Person, int> people;
    
    // Those keys are unique
    // Implement a overloading to operator < that
    // distinguish them
    people[Person("Daniel", 24)] = 0;
    people[Person("Daniel", 23)] = 1;
    people[Person("Jack", 13)] = 2;
    people[Person("Pedro", 20)] = 3;
    
    // The keys in a map are const
    // that is why print needs to be const as well
    for(map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
        it->first.print();
    }
    
    return 0;
}