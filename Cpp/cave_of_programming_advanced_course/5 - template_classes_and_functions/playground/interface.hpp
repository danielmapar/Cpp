#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <iostream>
using namespace std;

template<class T>
class Test {
private:
    T obj;
    
public:
    Test(T obj) : obj(obj) {};
    void print() { cout << obj << endl; };
    //void setObj(T obj);
    //T getObj();
};

#endif