#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

using namespace std;

namespace complex_numbers {
    
    class Complex {
    private:
        double real;
        double imaginary;
    public:
        Complex();
        Complex(double real, double imaginary);
        Complex(const Complex &other);
        Complex& operator=(const Complex &other);
        bool operator==(const Complex &other);
        bool operator!=(const Complex &other);
        Complex operator*();
        
        double getReal() const {
            return real;
        }
        
        double getImaginary() const {
            return imaginary;
        }
    };
    ostream& operator<<(ostream& os, const Complex &c);
}
#endif