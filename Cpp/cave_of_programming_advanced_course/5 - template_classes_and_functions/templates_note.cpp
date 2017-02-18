#include <iostream>

using namespace std;

/*
 It's because of the requirement for separate compilation and because templates are instantiation-style polymorphism.
 
 Lets get a little closer to concrete for an explanation. Say I've got the following files:
 
 foo.h
 declares the interface of class MyClass<T>
 foo.cpp
 defines the implementation of class MyClass<T>
 bar.cpp
 uses MyClass<int>
 
 "Instantiation-style polymorphism" means that the template MyClass<T> isn't really a generic class that can be compiled to code that can work for any value of T. That would add overhead such as boxing, needing to pass function pointers to allocators and constructors, etc. The intention of C++ templates is to avoid having to write nearly identical class MyClass_int, class MyClass_float, etc, but to still be able to end up with compiled code that is mostly as if we had written each version separately. So a template is literally a template; a class template is not a class, it's a recipe for creating a new class for each T we encounter. A template cannot be compiled into code, only the result of instantiating the template can be compiled.
 
 So when foo.cpp is compiled, the compiler can't see bar.cpp to know that MyClass<int> is needed. It can see the template MyClass<T>, but it can't emit code for that (it's a template, not a class). And when bar.cpp is compiled, the compiler can see that it needs to create a MyClass<int>, but it can't see the template MyClass<T> (only its interface in foo.h) so it can't create it.
 
 If foo.cpp itself uses MyClass<int>, then code for that will be generated while compiling foo.cpp, so when bar.o is linked to foo.o they can be hooked up and will work. We can use that fact to allow a finite set of template instantiations to be implemented in a .cpp file by writing a single template. But there's no way for bar.cpp to use the template as a template and instantiate it on whatever types it likes; it can only use pre-existing versions of the templated class that the author of foo.cpp thought to provide.
 
Check playground/interface.cpp for a more indepth explanation in terms of implementation
 
 */

template <class T, class K>
class Test {
private:
    T obj;
    
public:
    Test(T obj) : obj(obj) {
       // this->obj = obj;
    }
    
    void print() {
        cout << obj << endl;
    }
};


int main(void) {
    
    Test<string, int> test1("Hello");
    test1.print();
    
    return 0;
}