#include <iostream>
#include "Person.h"

using namespace std;

int main(void) {
    cout << "Start" << endl;

    Person person;

    person.setName("Daniel");
    cout << person.toString() << endl;
    cout << person.getName() << endl;

    cout << "End" << endl;
    return 0;
}