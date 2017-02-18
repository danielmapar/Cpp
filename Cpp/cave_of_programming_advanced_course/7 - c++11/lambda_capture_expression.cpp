#include <iostream>

using namespace std;

int a = 10;

int main(void) {
    
    int one = 1;
    int two = 2;
    int three = 3;
    
    // We can use the [] to expand the function access to the outter scope
    // Those will be passed by value
    [one, two](){ cout << one << " " << two << " Self initialized function" << endl; }();
    
    // By doing [=] you can capture all the variable in the current scope
    [=](){ cout << a << " " << two << " Self initialized function" << endl; }();
    
    // Capture all local variables by value, but capture three by reference
    
    [=, &three](){
        cout << three << " Self initialized function" << endl;
        three = 10;
    }();
    
    cout << "Three after: " << three << endl;
    
    // If you want to catch all values by reference, you just put a &
    // symbol
    
    [&](){
        cout << three << " Self initialized function" << endl;
        three = 20;
    }();
    
    cout << "Three after: " << three << endl;
    
    // We can catch everybody by reference, but also some by value
    [&, one](){
        cout << one << " Self initialized function" << endl;
        // you cant do one = 20;
    }();
    
    return 0;
}
