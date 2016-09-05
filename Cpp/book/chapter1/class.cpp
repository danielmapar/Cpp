//
//  class.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-21.
//
//

#include <iostream>

using std::cout;
using std::endl;

class Counter {

    public:
        Counter();
        int getCount();
        void increaseBy(int x);
    private:
        int count;
};

Counter::Counter() {
    count = 0;
}

int Counter::getCount(){
    return count;
}

void Counter::increaseBy(int x) {
    count += x;
}

int main(void) {
    
    Counter ctr;
    cout << ctr.getCount() << endl;
    ctr.increaseBy(20);
    cout << ctr.getCount() << endl;

    return 0;
}