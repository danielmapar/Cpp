#include <iostream>
#include <initializer_list>
#include <vector> 

using namespace std;

class Test {
public:
    Test(initializer_list<string> texts) {
        for(auto text : texts) {
            cout << text << endl;
        }
    }
    
    void print(initializer_list<string> texts) {
        for(auto text : texts) {
            cout << text << endl;
        }
    }
};


int main(void) {
    
    vector<int> numbers {1, 2, 3, 4, 5};
    cout << numbers[0] << endl;
    
    Test obj{"Daniel", "Pedro", "Jorge"};
    obj.print({"Daniel", "Pedro", "Jorge"});

    return 0;
}
