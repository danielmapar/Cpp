#include <iostream>
#include <iomanip>

using namespace std;

void printValues(unsigned int color, string step);

int main(void) {
    
    unsigned char alpha = 0xFF;
    unsigned char red = 0x12;
    unsigned char blue = 0x34;
    unsigned char green = 0x56;
    
    unsigned int color = alpha;
    
    printValues(color, "Step 1 - Add Alpha");
    
    // shift left adds 0's from the right to the left
    // shift right adds 0`s from the left to the right
    color <<= 8;
    
    printValues(color, "Step 2 - Shift");
    
    // We are doing a sum of binaries here
    // ex:
    // 00000000000000001111111100000000
    // +
    // 00000000000000000000000000010010
    // =
    // 00000000000000001111111100010010
    color += red;
    
    printValues(color, "Step 3 - Add Red");
    
    color <<= 8;
    
    printValues(color, "Step 4 - Shift");
    
    color += blue;
    
    printValues(color, "Step 5 - Add Blue");
    
    color <<= 8;
    
    printValues(color, "Step 5 - Shift");
    
    color += green;
    
    printValues(color, "Step 5 - Add Green");

    return 0;
}

void printValues(unsigned int color, string step) {
    cout << step << endl;
    cout << "color hex = " << setfill('0') << setw(8) << hex << color << endl;
    
    cout << "color binary = " << bitset<32>(color)  << endl;
}
