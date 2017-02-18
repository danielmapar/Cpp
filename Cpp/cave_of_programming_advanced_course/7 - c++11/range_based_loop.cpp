#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    
    // no need for []
    auto texts = {"one", "two", "three"};
    
    for(auto text : texts) {
        cout << text << endl;
    }
    
    cout << "-----------" << endl;
    
    vector<int> numbers;
    
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(9);
    numbers.push_back(11);
    
    for(auto number : numbers) {
        cout << number << endl;
    }
    
    cout << "-----------" << endl;
    
    string hello = "Hello";
    for(auto character : hello) {
        cout << character << endl;
    }
    
    return 0;
}