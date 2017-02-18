#include <iostream>

using namespace std;

// only c++14 deduce return types
auto test() {
    return 100;
}

// for c++11 we do (-> int) this is a trailing return type:
auto test2() -> int {
    return 100;
}

// works (that is why we have trailing return)
// remember, to use auto as a return type, you need to use
// trailing return (-> decltype(a*b))
template<class T>
auto mul(T a, T b) -> decltype(a*b){
    return a*b;
}


int test3() {
    return 100;
}

auto test4() -> decltype(test3()) {
    return test3();
}

// does not work
/*
decltype(a*b) mul(int a, int b){
    return a*b;
}*/


template <typename T>
void show() {
    cout << T() << endl;
}

int main(void) {

    auto value = 7;
    auto textPrimitive = "Hello";
    auto text = string("Hello");
    
    cout << value << endl;
    cout << textPrimitive << endl;
    cout << text << endl;
    
    cout << mul<>(10, 20) << endl;
    show<int>();
    
    
    cout << "--------" << endl;
    cout << mul(10, 20) << endl;
    cout << test4() << endl;
    return 0;
}