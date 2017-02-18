#include "interface.hpp"

template<class T>
Test<T>::Test(T obj) {
    this->obj = obj;
}

template<class T>
void Test<T>::print() {
    cout << obj << endl;
}

template<class T>
void Test<T>::setObj(T obj) {
    this->obj = obj;
}

template<class T>
T Test<T>::getObj() {
    return this->obj;
}

/*
 Consequently, the compiler needs to have access to the implementation of the methods, to instantiate them with the template argument (in this case int). If these implementations were not in the header, they wouldn't be accessible, and therefore the compiler wouldn't be able to instantiate the template.
 */

// If I dont tell the implementation which T`s it should
// create (the ones being used by the other .cpp`s), the other .cpp files wont have the implementation ready to be used.
// Templates are resolved in compilation time. Having said that, every single cpp is compiled into a different .o file and linked afterwards. Since this file is responsible to implement all class methods, it should also tell the compiler which versions of T it must create and make available, in order for the other .o files work properly.

// The best solution for that is to do all method implementation inline inside the .hpp file.

// Finally, a common solution (and hacky) to this is to write the template declaration in a header file, then implement the class in an implementation file (for example .tpp), and include this implementation file at the end of the header.

/*
 // Foo.h
 template <typename T>
 struct Foo
 {
 void doSomething(T param);
 };
 
 #include "Foo.tpp"
 
 // Foo.tpp
 template <typename T>
 void Foo<T>::doSomething(T param)
 {
 //implementation
 }
 
 This way, implementation is still separated from declaration, but is accessible to the compiler.
 */
template class Test<int>;