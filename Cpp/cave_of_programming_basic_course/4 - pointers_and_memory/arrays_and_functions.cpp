#include <iostream>

using namespace std;

void show1(string texts[]) {
    // This will return size of string *, not the 3 strings --> sizeof(texts)
    // We are passing a pointer to the function
    // If we want to get the size of the actual string we can do sizeof(*texts)
    // by dereferencing the texts variable
    //cout << "Sizeof texts inside show1 is: " << sizeof(texts) << endl;
    for (int i = 0; i < 3; i++) {
        cout << texts[i] << endl;
    }
}

void show2(const int nElements, string *texts) {
    for (int i = 0; i < nElements; i++) {
        cout << texts[i] << endl;
    }
}

// There shall be no references to references, no arrays of references, and no pointers to references.
// string &texts[3] => an array of references to strings (illegal)
// string (&texts)[3] => a reference to an array of strings
// [3] => you have to give the correct number, otherwise it breaks
void show3(string (&texts)[3]) {
    for (int i = 0; i < sizeof(texts)/sizeof(string); i++) {
        cout << texts[i] << endl;
    }
}

// There shall be no references to references, no arrays of references, and no pointers to references.
//void show4(string &texts[]) {
//    cout << "teste" << endl;
//}

//string *getArray() {
    // Don't return pointers to local variables (stack variables)
    // address of stack memory associated with local variable 'texts' returned
    // string texts[] = {"Demo", "Test"}; --> NO
    // string* texts = new string[2]; --> YES
    // return texts;
//}

//string* getArray() {
// Don't return pointers to local variables (stack variables)
// address of stack memory associated with local variable 'texts' returned
// string* texts = new string[2];
// return texts;
//}

int main(void) {
    
    int size = 0;
    
    cin >> size;
    
    // An Array must be declared with a constant value, you can't use a variable
    // string test[size];
    // Fix it by allocating memory
    // string *test = new string[size];
    
    //string test[size]; //wrong
    
    //string *test = new string[size]; //right
    
    string texts[] = {"pedro", "john", "jeff"};
    
    // That should return the sum of 3 strings
    cout << "Sizeof text is: " << sizeof(texts[0]) << endl;
    cout << "Sizeof texts inside main is: " << sizeof(texts) << endl;
    
    show3(texts);
    
    
    return 0;
}
