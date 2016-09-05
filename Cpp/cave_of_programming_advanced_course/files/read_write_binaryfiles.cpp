#include <iostream>
// file stream
#include <fstream>

using namespace std;

// pragma will reduce the padding to 0
// so a struct sizeof truely returns its original size
#pragma pack(push, 1)

struct Person {
    char name[50];
    int age;
    double weight;
};

#pragma pack(pop)

int main(void) {

    string fileName = "test.bin";
    
    string outputFile;
    
    outputFile.open(fileName, ios::binary);
    
    if (outputFile.is_open()) {
    
    }
    
    outputFile.close();
    
    
    return 0;
    
}