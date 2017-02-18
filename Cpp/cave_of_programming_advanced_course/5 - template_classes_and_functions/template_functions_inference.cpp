#include <iostream>

using namespace std;

// also works
//template <typename T>
template <class T>
void print(T n) {
    cout << n << endl;
}

void print(int n) {
    cout << "Non-template version: " << n << endl;
}

template <typename T>
void show() {
    cout << T() << endl;
}

int main(void) {
    
    print<int>(5);
    print<string>("Daniel");
    
    // also works -> type inference
    print(5); // calls the non template version
    print("Daniel");

    // if I include the <>.. even without the type inside
    // the compiler understands that I want the template version
    // diamond brackets
    // type inference
    print<>(20);
    
    // candidate template ignored: couldn't infer template argument 'T'
    // show();
    // also
    // candidate template ignored: couldn't infer template argument 'T'
    //show<>();
    // you need:
    show<int>();
    
    return 0;
}