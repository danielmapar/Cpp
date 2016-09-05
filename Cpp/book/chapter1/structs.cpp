//
//  structs.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-18.
//
//

#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

int main() {
    
    enum MealType {NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

    struct Passenger {
        string name;
        MealType mealPref;
        bool isFreqFlyer;
        string freqFlyerNo;
    };
    
    Passenger pass = {
        "John Smith",
        VEGETARIAN,
        true,
        "293145"
    };
    
    Passenger pass1 = {
        "John Smith 2",
        VEGETARIAN,
        true,
        "293145"
    };
    
    pass.name = "New name";
    pass.mealPref = LOW_FAT;
    
    cout << pass.name << endl;
    
    pass = pass1;
    
    cout << pass.name << endl;
    
    Passenger *pa = new Passenger;
    pa->name = "Daniel";
    pa->mealPref = VEGETARIAN;
    pa->isFreqFlyer = false;
    pa->freqFlyerNo = "NONE";
    
    cout << (*pa).name << endl;
    
    delete pa;
    
    cout << (*pa).name << endl;
    
    char *buffer = new char[500];
    buffer[3] = 'a';
    delete [] buffer;
    
    return 0;
    

}

