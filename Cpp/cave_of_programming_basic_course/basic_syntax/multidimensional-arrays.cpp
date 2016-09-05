#include <iostream>

using namespace std;

int main(void) {

    string animals[2][3] = {
        {"test", "test2", "test3"},
        {"test4", "test5", "test6"}
    };
    // we can missout the first index, but not the second one
    string animals2[][3] = {
        {"test", "test2", "test3"},
        {"test4", "test5", "test6"}
    };

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << animals[i][j] << "--" << flush;
        }
    }

    return 0;
}