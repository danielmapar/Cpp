#include <iostream>
#include "interface.hpp"

using namespace std;

int main(void) {
    
    Test<string> test("Daniel");
    test.print();
    
    return 0;
}