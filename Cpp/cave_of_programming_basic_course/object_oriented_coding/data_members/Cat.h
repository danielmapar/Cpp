#ifndef CAT_H_
#define CAT_H_

class Cat {
public:
    // in C++ 11 you can initialize a varible here
    // bool happy = true;
    // Initialize this bool variable inside a constructor
    // otherwise it will keep some trash inside of it
    bool happy;
    void speak();
    void makeHappy();
    void makeSad();
};

#endif