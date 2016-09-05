//
//  class3.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-21.
//
//

#include <iostream>

using std::cout;
using std::endl;

class Vect {
    
    public:
        Vect() {};
        Vect(int n);
        Vect(const Vect& vect2);
        ~Vect();
        Vect& operator=(const Vect& vect2);
    
    private:
        int* data;
        int size;
};

Vect::Vect(int n) {
    size = n;
    data = new int[n];
}

Vect::~Vect() {
    cout << "Deallocating" << endl;
    delete [] data;
}

Vect::Vect(const Vect& vect2) {
    size = vect2.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = vect2.data[i];
    }
}

Vect& Vect::operator=(const Vect& vect2) {
    if (this != &vect2) { // comparing pointer
        delete [] data;
        size = vect2.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = vect2.data[i];
        }
    }
    return *this;
}



int main(void) {
    
    //Vect *v = new Vect(30);
    //delete v;
    
    /**
     Example of lack of = operator overload
     
     Since we provided no copy constructor in Vect, the system uses its default, which simply copies each member of a to b. In particular it sets “b.data=a.data. Notice that this does not copy the contents of the array; rather it copies the pointer to the array’s initial element. This default action is sometimes called a shallow copy.”
     **/
    cout << "1" << endl;
    Vect a(100);
    cout << "2" << endl;
    Vect b = a; // call constructor
    cout << "3" << endl;
    Vect c = a;
    cout << "4" << endl;
    c = b;
    //c = a;
    //cout << "5" << endl;
    
    return 0;
}

