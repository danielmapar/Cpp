#include <iostream>
#include <vector>

using namespace std;

// run this program with the c++11 flag enabled
// g++ initialization_cpp11.cpp -std=c++11

int main(void) {
    
    // In C++ eleven I can put the braces immediately after the variable name,
    // and that will initialize it
    int value{5};
    
    cout << value << endl;
    
    string text{"Hello"};
    cout << text << endl;
    
    int numbers[]{1, 2, 3};
    
    cout << numbers[1] << endl;
    
    int *pInts = new int[3]{1, 2, 3};
    cout << pInts[1] << endl;
    delete [] pInts;
    
    int value1{};
    cout << value1 << endl;
    
    int *pSomething{&value};
    
    cout << *pSomething << endl;
    
    // In c++98 we have NULL. This is a macro that some of the headers already use
    // However, in c++11 we have nullptr
    int *pSomething2{nullptr}; // int *pSomething2{} == nullptr
    
    cout << pSomething2 << endl;
    
    int numbers1[5]{}; // this initialize every entry to 0
    cout << numbers1[0] << endl;
    
    struct {
        int value;
        string text;
    } s1{5, "Hi"};
    
    cout << s1.text << endl;
    
    // initialization list
    vector<string> strings{"one", "two", "three"};
    cout << strings[0] << endl;
    
    return 0;
}
