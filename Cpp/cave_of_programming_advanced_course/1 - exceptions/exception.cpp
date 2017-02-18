#include <iostream>

using namespace std;

void mightGoWrong();
void usesMightGoWrong();

void usesMightGoWrong() {
    mightGoWrong();
    cout << "Every thing fine!" << endl;
}

void mightGoWrong() {
    bool error = true;
    bool error2 = false;
    
    if (error) {
        // As soon as a throw statement is executed
        // the program wont continue executing / move to
        // the next line
        throw "Something going wrong";
    }
    
    if (error2) {
        throw string("String - error");
    }
}

int main(void) {
    
    try {
        usesMightGoWrong();
    } catch(int e) {
        cout << "Error code: " << e << endl;
    } catch(char const *e) {
        cout << "Error message: " << e << endl;
    /*
     Important details about exceptions:
     When we throw an exception that is an object, we should catch it by using a reference variable (Ex: string &e). Having said that, you may think that this is wrong, since the objected was created inside "mightGoWrong" and we are already out of scope "we are on main". However, the compiler treat exceptions differently and it is safe to do that. 
     Also, when we throw an exception that is an object: throw class(...)
     we dont need to use new, because again... the compiler understands that this is an exception, and cleans the object automaticly afterwards.
     */
    } catch (string &e) {
        cout << "Obj error message: " << e << endl;
    }
    
    cout << "Still running!" << endl;

    return 0;
}