#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Test {
private:
    string name;
public:
    Test(string name) : name(name) {
        cout << "Construct: " << name << endl;
    }
    Test(const Test &test);
    ~Test() {
        cout << "Destroy: " << name << endl;
    }
    Test& operator=(const Test &test);
    void print() {
        cout << name << endl;
    }
};

Test& Test::operator=(const Test &test) {
    cout << "Assignment operator: " << test.name << endl;
    this->name = test.name;
    return *this;
}

Test::Test(const Test &test) {
    cout << "Copy constructor: " << test.name << endl;
    this->name = test.name;
}

int main() {
    
    cout << "<<-------------------->>" << endl;
    cout << "Stack" << endl;
    cout << "<<-------------------->>" << endl;
    
    // LIFO
    stack<Test> testStack;
    
    testStack.push(Test("Mike"));
    testStack.push(Test("John"));
    testStack.push(Test("Sue"));
    /*
     Those Test("") will get out of scope right after they are copied
     by the .push function
     Construct: Mike
     Copy constructor: Mike
     Destroy: Mike
     Construct: John
     Copy constructor: John
     Destroy: John
     Construct: Sue
     Copy constructor: Sue
     Destroy: Sue
     */
    
    cout << "--------------------" << endl;
    
    // .top() returns a reference to a Test object in this case.
    // However, we are assigning the reference to a new variable
    // this will trigger a shallow copy (copy constructor) and the creation of a new object on the stack
    
    // This will guarantee that the object will stay aroung even after we do a .pop()
    
    //Test test1 = testStack.top();
    //test1.print();
    
    Test& test1 = testStack.top();
    test1.print();
    
    testStack.pop();
    // Destroy: Sue
    // test1 reference is now invalid, be careful
    test1.print(); // pointing to deallocated memory
    
    Test& test2 = testStack.top();
    test2.print();
    
    cout << "--------------------" << endl;
    
    Test test3("Daniel");
    Test test4("Pedro");
    
    // This will trigger the assignment operator
    test3 = test4;
    
    cout << "--------------------" << endl;
    
    while(testStack.size() > 0) {
        Test &test = testStack.top();
        test.print();
        testStack.pop();
    }
    
    cout << "<<-------------------->>" << endl;
    cout << "Queue" << endl;
    cout << "<<-------------------->>" << endl;
    
    // FIFO
    queue<Test> testQueue;
    
    testQueue.push(Test("Mike"));
    testQueue.push(Test("John"));
    testQueue.push(Test("Sue"));
    /*
     Those Test("") will get out of scope right after they are copied
     by the .push function
     Construct: Mike
     Copy constructor: Mike
     Destroy: Mike
     Construct: John
     Copy constructor: John
     Destroy: John
     Construct: Sue
     Copy constructor: Sue
     Destroy: Sue
     */
    
    while(testQueue.size() > 0) {
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }
    
    return 0;
}