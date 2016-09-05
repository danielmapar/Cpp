#include <iostream>

int main(void) {
    /*
    Output is generally buffered before it's written to the intended device. 
    That way, when writing to slow to access devices(like files), it doesn't have to 
    access the device after every single character.

    Flushing means emptying the buffer and actually writing it to the device.
    */
    std::cout << "Test" << std::flush;
    std::cout << "Test" << std::endl;

    return 0;
}