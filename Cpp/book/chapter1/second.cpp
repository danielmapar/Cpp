#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int x, y;
    
    enum Day {SUN, MON, TUE};
    enum Mood {HAPPY = 3, SAD = 9 };
    
    Day today = SUN;
    
    cout << "Please enter two numbers" << endl;
    cin >> x >> y;
    int sum = x + y;
    cout << "Their sum is: " << sum << endl;
    
    cout << today << endl;
    
    return EXIT_SUCCESS;
}