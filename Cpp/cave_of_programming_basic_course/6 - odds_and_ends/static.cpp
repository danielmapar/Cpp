#include <iostream>

using namespace std;

class Test {
private:
    static int count;
public:
    static int const MAX = 99;
    static void showInfo() {
        cout << count << endl;
    };
    void setCount(int val);
};

int Test::count = 20;

void Test::setCount(int val) {
    count = val;
}

int main(void){
    
    Test obj;
    obj.setCount(10);
    
    Test obj2;
    obj2.setCount(30);
    
    
    Test::showInfo();
    
    cout << Test::MAX << endl;
    

    return 0;
}