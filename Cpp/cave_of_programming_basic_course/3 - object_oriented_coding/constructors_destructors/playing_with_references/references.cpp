#include <iostream>

using namespace std;

class Wrapper
{
public:
    string& str;
    
    // Note, you cannot accept a const string& and store it in a string&, you would lose const-correctness in doing so.
    // Also, you have to initialize a reference immediately. It cant hold a NULL value
    // That is why we use the initialization list
    
    // Wont work!!!
    /*Wrapper(string& newStr)
    {
        str = newStr;
    }*/
    
    Wrapper(string& newStr) : str(newStr)
    {
    }
    
};

int main(void) {
    
    string str = "hello";
    string str3 = "hello2";
    
    string &str2 = str;
    // This will change the value of str from 'hello' to 'hello2'
    // References cant be rebound
    str2 = str3;
    
    cout << str << endl;
    
    Wrapper wrapper(str2);
    
    wrapper.str[0] = 'j'; // should change 'hello' to 'jello'
    cout << str << endl;
    
    return 0;
}