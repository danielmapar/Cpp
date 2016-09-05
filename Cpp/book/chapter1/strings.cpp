//
//  strings.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-18.
//
//

#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;

int main() {

    string s = "to be";
    string t = "not " + s;
    string u = s + " or " + t;
    if (s > t) {
        cout << u;
    }
    string s = "John";
    int i = s.size();
    char c = s[3];
    s += " Smith"
    // s.c_str()
    
    return EXIT_SUCCESS;

}

