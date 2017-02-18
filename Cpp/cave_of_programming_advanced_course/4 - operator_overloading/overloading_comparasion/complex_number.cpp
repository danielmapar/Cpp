#include "complex_number.hpp"

namespace complex_numbers {
    
    ostream& operator<<(ostream &out, const Complex &c) {
        out << "(" << c.getReal() << "." << c.getImaginary() << ")";
        return out;
    }
    
    Complex operator+(const Complex &a, const Complex &b) {
        return Complex(a.getReal()+b.getReal(), a.getImaginary()+b.getImaginary());
    }
    
    Complex operator+(const Complex &a, double d) {
        return Complex(a.getReal()+d, a.getImaginary()+d);
    }
    
    Complex operator+(double d, const Complex &a) {
        return Complex(a.getReal()+d, a.getImaginary()+d);
    }
    
    Complex::Complex(): real(0), imaginary(0) {}
    
    Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) { }
    
    Complex::Complex(const Complex &other) {
        cout << "Copy constructor" << endl;
        *this = other;
    }
    
    Complex& Complex::operator=(const Complex &other) {
        cout << "Assignment operator" << endl;
        this->real = other.real;
        this->imaginary = other.imaginary;
        return *this;
    }
    
    bool Complex::operator==(const Complex &other) {
        return ((this->getReal() == other.getReal()) && (this->getImaginary() == other.getImaginary()));
    }
    
    bool Complex::operator!=(const Complex &other) {
        //return (this->getReal() != other.getReal() || this->getImaginary() != other.getImaginary());
    
        return !(*this==other);
    }
    
}

using namespace complex_numbers;

/*
 This does not mean that a function 'main' can not be defined as you did. It just means that a global namespace scope definition of 'main' in accordance with the Standard defined signature is required for a free standing program. hosted program
 */
int main(void) {
    
    Complex c(1.1, 2.2);
    // both are copy constructors
    Complex c2(2.1, 2.2);
    Complex c3(c2);
    
    if (c2 == c) {
        cout << "Equal" << endl;
    } else {
        cout << "Not equal" << endl;
    }
    
    if (c2 != c) {
        cout << "Not equal" << endl;
    } else {
        cout << "Equal" << endl;
    }
    
    return 0;
}