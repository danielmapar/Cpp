#include <iostream>

using namespace std;

int main(void) {
    
    //http://www.cplusplus.com/doc/tutorial/other_data_types/
    union mytypes_t {
        char c;
        int i;
        float f;
    } mytypes;
    
    mytypes.c = '0';
    
    cout << mytypes.c << endl;
    cout << mytypes.i << endl;
    
    
    bitset<64> mytypesChar(mytypes.c);
    cout << mytypesChar << endl;
    
    bitset<64> mytypesInt(mytypes.i);
    cout << mytypesInt << endl;
    
    bitset<64> mytypesFloat(mytypes.f);
    cout << mytypesFloat << endl;
    
    cout << "---------" << endl;
    
    union mix_t {
        int l;
        struct {
            short hi;
            short lo;
        } s;
        char c[4];
    } mix;
    
    mix.s.hi = 10;
    mix.s.lo = 20;
    
    // 16 bits -> 0000000000001010
    cout << mix.s.hi << endl;
    bitset<64> mixShortHi(mix.s.hi);
    cout << mixShortHi << endl;
    
    // 16 bits -> 0000000000010100
    cout << mix.s.lo << endl;
    bitset<64> mixShortLo(mix.s.lo);
    cout << mixShortLo << endl;
    
    
    // 32 bits -> 0000000000101000000000000001010
    // 32 bits -> 000000000010100 0000000000001010
    cout << mix.l << endl;
    bitset<64> mixIntL(mix.l);
    cout << mixIntL << endl;
    
    cout << "---------" << endl;
    
    // Anonymous unions
    struct book2_t {
        char title[50];
        char author[50];
        union {
            float dollars;
            int yen;
        };
    } book2;
    
    book2.yen = 10;
    
    cout << book2.yen << endl;
    
    return 0;
}