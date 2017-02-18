#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class Check {
public:
    bool operator()(string &test){
        return test.size() == 5;
    }
} check1;

bool check(string &test) {
    return test.size() == 3;
}

// this function can accept anything that is callable
void run(function<bool(string&)> check) {
    string test("Dog");
    cout << check(test) << endl;
}

int main(void) {
    
    int size = 5;
    
    vector<string> vec{"one", "two", "three"};
    
    int count = count_if(vec.begin(), vec.end(), [size](string test){ return test.size() == size; });
    cout << count << endl;
    
    cout << "---------" << endl;
    
    int count2 = count_if(vec.begin(), vec.end(), check);
    cout << count2 << endl;
    
    cout << "---------" << endl;
    
    int count3 = count_if(vec.begin(), vec.end(), Check());
    count3 = count_if(vec.begin(), vec.end(), check1);
    cout << count3 << endl;
    
    cout << "---------" << endl;
    
    // We can pass any kind of function that returns bool and
    // gets a string reference as input
    run(check1);
    run(check);
    run([size](string test){ return test.size() == size; });
    
    cout << "---------" << endl;
    
    function<int(int, int)> add = [](int one, int two){ return one + two; };
    
    cout << add(10, 20) << endl;
    
    return 0;
}
