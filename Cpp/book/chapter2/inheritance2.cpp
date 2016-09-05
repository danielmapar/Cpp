//
//  Inhetirance2.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-28.
//
//


#include <iostream>

using std::cout;
using std::endl;

class Progression {
public:
    Progression(long f = 0) : first(f), cur(f) {}
    virtual ~Progression() {}
    void printProgression(int n);

protected:
    virtual long firstValue();
    virtual long nextValue();
    long first;
    long cur;
};

void Progression::printProgression(int n) {
    cout << firstValue();
    for(int i = 2; i <= n; i++) {
        cout << ' ' << nextValue();
    }
    cout << endl;
}

long Progression::firstValue() {
    cur = first;
    return cur;
}

long Progression::nextValue() {
    return ++cur;
}

class ArithProgression : public Progression {
public:
    ArithProgression(long i = 1);
protected:
    virtual long nextValue();
    long inc;
};

ArithProgression::ArithProgression(long i) : Progression(), inc(i) { }

long ArithProgression::nextValue() {
    cur += inc;
    return cur;
}

class GeomProgression : public Progression {
public:
    GeomProgression(long b = 2);

protected:
    virtual long nextValue();
    long base;
};

GeomProgression::GeomProgression(long b) : Progression(1), base(b) { }

long GeomProgression::nextValue() {
    cur *= base;
    return cur;
}

class FibonacciProgression : public Progression {
public:
    FibonacciProgression(long f = 0, long s = 1); // constructor

protected:
    virtual long firstValue();
    virtual long nextValue();
    long second;
    long prev;
};

FibonacciProgression::FibonacciProgression(long f, long s) : Progression(f), second(s), prev(second - first) { }

long FibonacciProgression::firstValue() {
    cur = first;
    prev = second - first;
    return cur;
}

long FibonacciProgression::nextValue() {
    long temp = prev;
    prev = cur;
    cur += temp;
    return cur;
}

int main(void) {
    const int SIZE = 4;
    // array of Progression pointers
    Progression *p[SIZE];
    p[0] = new Progression(1000);
    p[1] = new ArithProgression(1000);
    p[2] = new GeomProgression(1000);
    p[3] = new FibonacciProgression();
    
    for (int i = 0; i < SIZE; i++) {
        p[i]->printProgression(10);
    }

    delete p[0];
    delete p[1];
    delete p[2];
    delete p[3];
    
    // pointer to the first Progression object of an array
    Progression *arr = new Progression[10]();
    arr[0].printProgression(100);
    
    delete[] arr;
    
    return 0;
}