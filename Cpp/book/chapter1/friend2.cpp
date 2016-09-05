//
//  friend2.cpp
//  
//
//  Created by Daniel Marchena on 2015-09-22.
//
//

#include <iostream>

class Vector {
    public:
    private:
        double coords[3];
        // No, there's no difference - you just tell that class B is a friend of class A and now can access its private and protected members, that's all.
        friend class Matrix; // Give matrix access to coords
};

class Matrix {
    public:
        Vector multiply(const  Vector &v);
    private:
        double a[3][3];
};

Vector Matrix::multiply(const Vector &v) {
    Vector w;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            w.coords[i] += a[i][j] * v.coords[j];
        }
    }
    return w;
}

int main(void) {
    Vector vet;
    Matrix mat = Matrix();
    mat.multiply(vet);
    
    return 0;
}