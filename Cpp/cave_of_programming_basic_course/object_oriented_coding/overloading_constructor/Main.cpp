#include <iostream>
#include "Person.h"

using namespace std;

int main(void) {
    cout << "Start" << endl;

    Person person;

    person.setName("Daniel");
    cout << person.toString() << endl;

    Person person2("Pedro", 30);
    cout << person2.toString() << endl;

    cout << "End" << endl;
    return 0;
}