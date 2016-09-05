//
//  class2.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-21.
//
//

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Passanger {
    public:
        Passanger() {} ;
        Passanger(const string& name);
        Passanger(const Passanger& pass);
        Passanger(const string& nm, const string& ffn);
        bool isFrequentFlyer() const;
        //bool isFrequentFlyer() const { return isFrequentFlyer; }
        void makeFrequentFlyer(const string& newFreqFlyerNo = "None");
        string getFrequentFlyer() const { return freqFlyerNo; }
        string getName() const { return name; }
    
    private:
        string name;
        bool isFreqFlyer;
        string freqFlyerNo;

};

Passanger::Passanger(const string& newName) {
    name = newName;
}

// copy constructor
Passanger::Passanger(const Passanger& pass) {
    name = pass.name;
    isFreqFlyer = pass.isFreqFlyer;
    freqFlyerNo = pass.freqFlyerNo;
}

// initializer list
Passanger::Passanger(const string& nm, const string& ffn) :
    name(nm), freqFlyerNo(ffn) { // initializing string class
}

bool Passanger::isFrequentFlyer() const {
    return isFreqFlyer;
}

void Passanger::makeFrequentFlyer(const string& newFreqFlyerNo) {
    isFreqFlyer = true;
    freqFlyerNo = newFreqFlyerNo;
}


int main(void) {
    
    Passanger pass;
    pass.makeFrequentFlyer();
    cout << pass.isFrequentFlyer() << endl;
    cout << pass.getFrequentFlyer() << endl;
    
    //string name = "Novo";
    
    Passanger pass2("Novo");
    cout << pass2.getName() << endl;
    
    Passanger *passPtr = new Passanger("Daniel");
    Passanger *passPtr2 = new Passanger(*passPtr);
    Passanger *passPtr3 = new Passanger("Nome", "Num");
    
    cout << passPtr->getName() << endl;
    cout << passPtr2->getName() << endl;
    cout << passPtr3->getName() << endl;
    
    delete passPtr;
    delete passPtr2;
    delete passPtr3;
    
    return 0;
}