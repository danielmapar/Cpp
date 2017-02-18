#include <iostream>

using namespace std;

int main(void) {
    
    int other = 10;
    int number = 10;
    // read it from the right to the left
    // pointer to an int that is constant
    const int * pValue = &number;
    
    // the int is a constant. I cant change the value that the pointer is pointing to
    // cant do: *pValue = 20;
    // can do: pValue = &other;
    
    // constant pointer to an int
    int * const pValue2 = &number;
    *pValue2 = 20;
    // cant do: pValue2 = &other;
    //pValue2 = &other;
    
    // constant pointer to an int that is a constant
    const int * const pValue3 = &number;
    // cant do: *pValue3 = 20;
    // cant do: pValue3 = &other;
    
    
    // const int and int const are identical

    
    return 0;
}
