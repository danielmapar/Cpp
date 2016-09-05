#include <iostream>
// file stream
#include <fstream>

using namespace std;

int main(void) {
    
    // fstream supports both read and write
    // depends on ios::out and ios::in
    
    // output file stream
    // ofstream outFile;
    
    // input file stream
    // ifstream inFile;
    
    fstream inFile;
    string inputFileName("text.txt");
    
    // inFile.open(inputFileName);
    inFile.open(inputFileName, ios::in);
    
    if (inFile.is_open()) {
        string line;
        
        //inFile >> line;
        // EOF - end of file
        // inFile uses operator overloading for bool
        // and the ! sign
        // so you can do while(inFile) {} 
        while (!inFile.eof()) {
            getline(inFile, line);
            cout << line << endl;
        }
        
        inFile.close();
    } else {
        cout << "Could not read file: " << inputFileName <<  endl;
    }
    
    return 0;
    
}