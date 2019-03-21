#include <iostream>

using namespace std;

int main(void) {

    string animals[][3] = {
        { "fox", "dog", "cat" },
        { "mouse", "squirrel", "parrot"}
    };

    cout << "Size of the class instance and its data members: " << sizeof(animals[0][0]) << endl;
    
    unsigned int numOfElements = sizeof(animals[0])/sizeof(string);
    unsigned int arraysSize = sizeof(animals)/sizeof(animals[0]);
    
    //ou the size of the class instance and its data members, not the length of the string. To get that, use:
    cout << "String: " << sizeof(string) << endl;
    // cout << s.size();
    cout << "Arrays Size: " << arraysSize << endl;
    cout << "Num of Elements: " << numOfElements << endl;

    for (unsigned int i = 0; i < arraysSize; i++) {
        for (unsigned int j = 0; j < numOfElements; j++) {
            cout << animals[i][j] << endl;
        }
    }
    
    return 0;
}
