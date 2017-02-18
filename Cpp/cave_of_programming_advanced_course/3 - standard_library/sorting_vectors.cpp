#include <iostream>
#include <vector>

using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(int id, string name) : id(id), name(name) {}
    void print() {
        cout << id << ": " << name << endl;
    }
    bool operator<(const Test& test) const;
    friend bool comp(const Test &a, const Test &b);
};

bool Test::operator<(const Test& test) const {
    return this->id < test.id;
}

bool comp(const Test &a, const Test &b) {
    return a.id < b.id;
}


int main(void) {

    vector<Test> tests;
    
    tests.push_back(Test(2, "Daniel"));
    tests.push_back(Test(4, "John"));
    tests.push_back(Test(1, "Pedro"));
    tests.push_back(Test(0, "Maria"));
    
    //std::sort
    // sort(tests.begin(), tests.end());
    // comp is a function pointer
    sort(tests.begin(), tests.end(), comp);
    
    // sort the first three only
    //sort(tests.begin(), tests.begin()+3, comp);
    
    for (int i = 0; i < tests.size(); i++) {
        tests[i].print();
    }
    
    return 0;
}