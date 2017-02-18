#include <iostream>

class CanGoWrong {
public:
    CanGoWrong() {
        char *pMemory = new char[9999999999999999];
        delete [] pMemory;
    }
    
};


int main(void) {
    
    try {
        CanGoWrong wrong;
    } catch (std::bad_alloc &e) {
        std::cout << "Bad alloc: " << e.what() << std::endl;
    }

    return 0;
}