#include <iostream>
#include <set>

using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test() : id(0), name("") {}
    Test(int id, string name): id(id), name(name) {}
    void print() const {
        cout << id << ":" << name << endl;
    }
    bool operator<(const Test &test) const {
        return this->id < test.id;
    }
};

int main(void) {

    // unique and ordered values
    set<int> numbers;
    
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(30);
    numbers.insert(40);
    numbers.insert(50);
    numbers.insert(60);
    numbers.insert(70);
    numbers.insert(80);
    numbers.insert(90);
    numbers.insert(100);
    numbers.insert(110);
    numbers.insert(120);
    
    for(set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    
    set<int>::iterator itFind = numbers.find(30);
    
    if (itFind != numbers.end()) {
        cout << *itFind << endl;
    }
    
    // returns 1 if find, and 0 if not
    if (numbers.count(30)) {
        cout << "Number found" << endl;
    }
    
    cout << "----------------------------" << endl;
    
    set<Test> tests;
    
    tests.insert(Test(6, "Daniel"));
    tests.insert(Test(2, "Pedro"));
    tests.insert(Test(3, "John"));
    tests.insert(Test(4, "Maria"));
    tests.insert(Test(5, "Patrick"));
    
    for(set<Test>::iterator it = tests.begin(); it != tests.end(); it++) {
        it->print();
    }

    return 0;
}