#include <iostream>

using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(): id(0), name("") {}
    Test(int id, string name): id(id), name(name) {}
    void print() {
        cout << id << ": " << name << endl;
    }
    Test& operator=(const Test &test) {
        this->id = test.id;
        this->name = test.name;
        
        return *this;
    }
    Test(const Test& test) {
        *this = test;
    }
    friend ostream& operator<<(ostream& os, const Test &test);
};

// The << operator is supposedly pronounced "put-to", except of course when you're actually twiddling bits!
ostream& operator<<(ostream& os, const Test &test) {
    os << test.id << ": " << test.name;
    return os;
}

int main(void) {
    
    Test test1(10, "Mike");
    
    // from left to right
    // 1)cout << test1
    // 2) cout << endl;
    cout << test1 << endl;
    operator<<(cout, test1) << endl;
    
    return 0;
}
