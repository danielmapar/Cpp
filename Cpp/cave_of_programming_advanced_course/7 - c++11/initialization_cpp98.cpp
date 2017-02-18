#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int values[] = {1, 4, 5};
    
    cout << values[0] << endl;
    
    class C {
    public:
        string text;
        int id;
    };
    
    C c1 = {"Hello", 7};
    
    cout << c1.text << endl;
    
    struct S {
        string text;
        int id;
    };
    
    S s1 = {"Hello1", 8};
    
    cout << s1.text << endl;
    
    //struct S1 {
    struct {
        string text;
        int id;
    } s2 = {"Hello2", 8}, s3 = {"Test", 10};
    
    cout << s2.text << " " << s3.text << endl;
    
    // In c++ 11 this can be done way more efficiently 
    vector<string> strings;
    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");
    
    return 0;
}
