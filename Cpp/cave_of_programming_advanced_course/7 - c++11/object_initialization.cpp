#include <iostream>

using namespace std;

class Test {
    // you can initialize variables by using the
    // initialization_list property of C++11
    int id{1};
    string name{"Daniel"};
    // you can also do
    int id2 = 10;

public:
    // c++98
    //Test() {}
    // c++11
    Test() = default;
    //Test(const Test &other) = default;
    Test &operator=(const Test &other) = default;
    // I can also delete the copy constructor
    Test(const Test &other) = delete;
    
    
    Test(string name) : name(name) {}
    string getName() {
        return this->name;
    }
    friend ostream& operator<<(ostream& out, Test &test);
};

ostream& operator<<(ostream& out, Test &test) {
    out << test.name << " " << test.id;
    return out;
}

int main() {
    
    // Every instance of Test will get initialized with
    // those values
    Test test;
    Test test2(string("Pedro"));
    
    cout << test << endl;
    cout << test2 << endl;
    
    Test test3;
    test3 = test;
    
    /*
     Wont work since we deleted the default implementation by using
     = delete
    Test test4 = test3;
     */
    

    return 0;
}
