#include <iostream>

using namespace std;

int main(void) {

    int values[] = {4, 7, 3, 4};

    cout << "Size of values array: " << sizeof(values) << endl;
    cout << "Size of type int: " << sizeof(int) << endl;

    for(unsigned int i = 0; i < sizeof(values)/sizeof(int); i++) {
        cout << values[i] << endl;
    }

    return 0;
}