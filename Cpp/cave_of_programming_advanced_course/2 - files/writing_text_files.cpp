#include <iostream>
// file stream
#include <fstream>

using namespace std;

int main(void) {
    
    // output file stream
    //ofstream outFile;
    
    fstream outFile;
    string outputFileName("text.txt");

    outFile.open(outputFileName, ios::out);

    if (outFile.is_open()) {
        outFile << "Hello there" << endl;
        outFile << 123 << endl;
        outFile.close();
    } else {
        cout << "Could not create file: " << outputFileName <<  endl;
    }

    return 0;
    
}