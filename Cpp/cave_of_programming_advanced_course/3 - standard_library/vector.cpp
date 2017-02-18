#include <iostream>
#include <vector>

using namespace std;

/*
 Remember! We can only push new values
 to the end of a vector. However, if we use a list,
 we can push values any where (start, middle, end)
 */

int main(void) {
    
    vector<string> strings; //(5);
    
    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");
    
    // operator overloaded
    //strings[3] = "dog";
    
    cout << strings[0] << endl;
    
    cout << strings.size() << endl;
    
    cout << "Loop using a for" << endl;
    
    // the index basic could be a little less safe since you
    // can modify the vector values
    // if a const interator that is not the case
    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }
    cout << "------" << endl;
    
    // vector<string>::iterator it = strings.begin();
    // strings.end() is the element after the end of the vector
    // not the last one
    
    cout << "Loop using a iterator" << endl;
    
    for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++) {
        cout << *it << endl;
    }
    
    cout << "------" << endl;
    
    vector<string>::iterator it = strings.begin();
    it += 2;
    
    cout << *it << endl;
    
    return 0;
}