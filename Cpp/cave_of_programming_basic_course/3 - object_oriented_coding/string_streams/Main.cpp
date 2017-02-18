#include <iostream>
#include <sstream> 

using namespace std;

int main(void) {
    string name = "Bob";
    int age = 32;

    // it uses namespace std
    stringstream ss;

    ss << "Name is: ";
    ss << name;
    ss << " age is: ";
    ss << age;

    //string info = "Name: " + name + "; age: " + age;
    //cout << info << endl;
    string info = ss.str();
    cout << info << endl;
    return 0;
}