#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    
    char ch = 'Q';
    char *p = &ch;
    
    cout << *p;
    ch = 'Z';
    cout << *p;
    *p = 'X';
    cout << ch << endl;
    
    double f[5];
    int m[10];
    
    f[4] = 2.5;
    m[2] = 4;
    cout << f[m[2]] << endl;
    
    int aut[] = {1, 2, 3, 4};
    
    int mat[4][5];
    
    mat[0][0] = 2;
    mat[0][1] = 3;
    
    cout << mat[0][0] + mat[0][1] << endl;
    
    char c[] = {'a', 'b', 'c'};
    char *p2 = c; // c[0] or &(c+0)
    char *q = &c[0];
    cout << c[2] << p2[2] << *(p2+2) << q[2] << endl;
    
    return EXIT_SUCCESS;
}