// double ended queue - deck

#include <iostream>
#include <deque>

using namespace std;

class Test {
private:
    string name;
public:
    Test(string name) : name(name) {}
    void print() {
        cout << this->name << endl;
    }
};

int main(void) {
 
    deque<Test> testDeque;
    
    testDeque.push_front(Test("Mike"));
    testDeque.push_back(Test("John"));
    testDeque.push_front(Test("Sue"));
    
    while(testDeque.size() > 0) {
        Test &test = testDeque.front();
        test.print();
        testDeque.pop_front();
    }
    
    /*while (!testDeque.empty())
    {
        Test &test = testDeque.front();
        test.print();
        testDeque.pop_front();
    }*/
    
    return 0;
}