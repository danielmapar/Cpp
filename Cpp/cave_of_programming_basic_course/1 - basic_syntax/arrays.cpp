#include <iostream>

using namespace std;

int main(void) {

    int values[3] = {1,2,3};
    
    // initialize it when you declare it
    // and you dont need to specify the size of it
    int values2[] = {1,2,3}; 

    int values3[8] = {}; // set it all to 0

    cout << values[0] << "-->" << &(values[0]) << endl;
    cout << values2[0] << "-->" << &(values2[0]) << endl;

    cout << "-------" << endl;

    for (int i = 0; i < 8; i++) {
        cout << values3[i] << "-->" << &(values3[i]) << endl;
        cout << (values3+i) << endl;
    }
    cout << "-------" << endl;

    string texts[] = {"test", "test2", "test3"};

    for(int i = 0; i < 3; i++) {
        cout << texts[i] << "-->" << &(texts[i]) << endl;
    }

    return 0;
}
