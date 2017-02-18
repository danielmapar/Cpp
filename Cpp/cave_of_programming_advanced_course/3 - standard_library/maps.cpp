#include <iostream>
#include <map>

using namespace std;

int main(void) {
    
    map<string, int> ages;
    
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;
    ages["Vic"] = 99;
    
    ages["Mike"] = 70;
    
    cout << ages["Raj"] << endl;
    
    // Simply trying to check is in a map
    // creates it.. we dont want that
    cout << ages["Sue"] << endl;
    
    
    pair<string, int> addToMap("Daniel", 100);
    ages.insert(addToMap);
    
    ages.insert(pair<string, int>("John", 98));
    
    ages.insert(make_pair("Kohn", 28));
    
    map<string,int>::iterator it;
    
    if ( (it = ages.find("Vic")) != ages.end()) {
        cout << "Found: " << it->first << " " << it->second << endl;
    } else {
        cout << "Key not found!" << endl;
    }
    
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    
    cout << "-----------" << endl;
    
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        pair<string, int> age = *it;
        
        cout << age.first << ": " << age.second << endl;
    }
    
    return 0;
}