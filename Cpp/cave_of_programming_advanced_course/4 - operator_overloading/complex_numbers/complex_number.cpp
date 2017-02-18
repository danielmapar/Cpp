#include "complex_number.hpp"

namespace complex_numbers {
    
    ostream& operator<<(ostream &out, const Complex &c) {
        out << "(" << c.getReal() << "." << c.getImaginary() << ")";
        return out;
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
    
}

using namespace complex_numbers;

/*
 This does not mean that a function 'main' can not be defined as you did. It just means that a global namespace scope definition of 'main' in accordance with the Standard defined signature is required for a free standing program. hosted program
 */
int main(void) {
    
    Complex c(1.1, 2.2);
    Complex c2 = c;
    Complex c3(c);
    cout << c2 << " " << c << endl;
    
    return 0;
}