#include <iostream>

using namespace std;

int main(void) {

    string animals[][3] = {
        { "fox", "dog", "cat" },
        { "mouse", "squirrel", "parrot"}
    };

    unsigned int numOfElements = sizeof(animals[0])/sizeof(string);
    unsigned int arraysSize = sizeof(animals)/sizeof(animals[0]);

    cout << "String: " << sizeof(string) << endl;
    cout << "Arrays Size: " << arraysSize << endl;
    cout << "Num of Elements: " << numOfElements << endl;

    for (unsigned int i = 0; i < arraysSize; i++) {
        for (unsigned int j = 0; j < numOfElements; j++) {
            cout << animals[i][j] << endl;
        }
    }
    
    return 0;
}