#include <iostream>

using namespace std;

int main() {
    
    int cats = 5;
    
    // By using mutable you dont change the variable in the outter scope, but you enable the lambda function to change its local copy
    [cats]() mutable {
        cats = 8;
        cout << cats << endl;
    } ();
    
    return 0;

}
