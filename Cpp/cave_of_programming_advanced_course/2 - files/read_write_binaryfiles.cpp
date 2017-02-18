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

    Person someone = {
        "Frodo",
        220,
        0.8
    };
    
    Person someoneElse = {};
    
    string fileName = "test.bin";
    
    // or use ofstream without the need to supply
    // ios::out|ios::binary, just ios::binary
    fstream outputFile;
    
    cout << "ios::binary: " << sizeof(ios::binary) << endl;
    cout << "ios::binary: " << ios::binary << endl;
    cout << "ios::binary: " << bitset<32>(ios::binary)  << endl;
    
    cout << "ios::out: " << sizeof(ios::out) << endl;
    cout << "ios::out: " << ios::out << endl;
    cout << "ios::out: " << bitset<32>(ios::out)  << endl;
    
    cout << "ios::out and ios::binary: " << (ios::out|ios::binary) << endl;
    cout << "ios::out and ios::binary: " << bitset<32>(ios::binary|ios::out)  << endl;

    // Write binary file
    
    outputFile.open(fileName, ios::binary|ios::out);
    
    if (outputFile.is_open()) {
        
        //outputFile.write((char *)&someone, sizeof(Person));
        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        
        outputFile.close();
    } else {
    
        cout << "Could not create file: " << fileName;
    }
    
    // Read binary file
    
    fstream inputFile;
    
    inputFile.open(fileName, ios::binary|ios::in);
    
    if (inputFile.is_open()) {
        
        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
        
        inputFile.close();
    } else {
        
        cout << "Could not read file: " << fileName;
    }
    
    cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.weight << endl;
    
    return 0;
    
}

/* About reinterpret_cast
 
 The C++ standard guarantees the following:
 
 static_casting a pointer to and from void* preserves the address. That is, in the following, a, b and c all point to the same address:
 
 int* a = new int();
 void* b = static_cast<void*>(a);
 int* c = static_cast<int*>(b);
 reinterpret_cast only guarantees that if you cast a pointer to a different type, and then reinterpret_cast it back to the original type, you get the original value. So in the following:
 
 int* a = new int();
 void* b = reinterpret_cast<void*>(a);
 int* c = reinterpret_cast<int*>(b);
 
 a and c contain the same value, but the value of b is unspecified. (in practice it will typically contain the same address as a and c, but that's not specified in the standard, and it may not be true on machines with more complex memory systems.)
 
 For casting to and from void*, static_cast should be preferred.*/