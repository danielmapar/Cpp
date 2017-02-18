#include <iostream>

using namespace std;

int main(void) {

    string texts[] = {"daniel", "pedro", "angela"};

    string *text = texts;

    int size = sizeof(texts)/sizeof(string);
    
    cout << size << endl;

    for (int i = 0; i < size; i++) {
        cout << text[i] << endl;
        cout << *(text+i) << endl;
        cout << (text+i) << endl;
    }
    
    char *ptr = NULL;
    int num = 10;
    ptr = (char*) &num;
    
    cout << *ptr << endl;
    
    while(true) {
        cout << *(ptr++) << flush;
    }

    return 0;
}
