#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

    string filename = "stats.txt";
    ifstream input;
    
    input.open(filename);
    
    if (input.is_open()) {
        while(input) {
            string line;
            getline(input, line, ':');
            
            int population;
            input >> population;
            
            // will discart the new line character
            //input.get();
            // read white space
            
            cout << "'" << line << "'" << " -- " << "'"<< population << "'" << endl;
            
            input >> ws;
        }
    } else {
        return 1;
    }
    
    input.close();
    
    return 0;
}