// c++11 lambda is a syntactic sugar for functors

// functors is pre c++11 and works in c++11

#include <iostream>

using namespace std;

// abstract struct/class
struct Test {
    virtual bool operator()(string &text)=0;
    virtual ~Test(){}
};

struct MatchTest : public Test {
    // the round brackets is an operator
    // a functor is a struct/class that overloads this
    // brackets operator
    
    // unlike regular functions, functors can contain
    // state (variables). 
    bool operator()(string &text) {
        return text == "lion";
    }
};

void check(string text, Test &test) {
    if (test(text)) {
        cout << "Text matches!" << endl;
    } else {
        cout << "No match." << endl;
    }
}

int main(void) {

    string value = "lion";
    
    MatchTest pred;
    cout << pred(value) << endl;
    
    check(value, pred);
    
    return 0;
    
}