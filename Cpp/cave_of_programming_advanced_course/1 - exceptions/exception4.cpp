#include <iostream>
#include <exception>

using namespace std;

class MyException : public bad_alloc {
public:
    virtual const char *what() const throw() {
        return "Custom: Something bad happened.";
    }
};

void goesWrong() {

    bool error1Detected = false;
    bool error2Detected = false;
    bool error3Detected = true;
    
    if (error3Detected) {
        throw MyException();
    }
    
    if (error1Detected) {
        throw bad_alloc();
    }
    
    if (error2Detected) {
        throw exception();
    }
}


int main(void) {
    
    /*
        As soon as the exception is cauth by one of the
        catch statements, it wont check the other ones
        
        Also. if I do a throw MyException() with the following try catch:
     
        try {
            goesWrong();
        } catch (bad_alloc &e) {
            std::cout << "Bad alloc: " << e.what() << std::endl;
        } catch (MyException &e) {
            std::cout << "MyException: " << e.what() << std::endl;
        } catch (exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        When we compile we will see the following warning:
     
        warning: exception of type 'MyException &' will be caught by earlier handler [-Wexceptions]
        
        Also, a child of "bad_alloc" wont be able to catch a "throw bad_alloc()". However, a "throw MyException()" will be catched earlier by the bad_alloc catch block.
     
      */
    
    // Remember that what is a virtual method
    // that will do dynamic binding to find the right
    // function to execute
    try {
        goesWrong();
    } catch (MyException &e) {
        std::cout << "MyException: " << e.what() << std::endl;
    } catch (bad_alloc &e) {
        std::cout << "Bad alloc: " << e.what() << std::endl;
    } catch (exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}