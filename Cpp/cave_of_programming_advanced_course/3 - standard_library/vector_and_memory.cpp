#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    
    // size of 20, and every initialized with 1
    //vector<double> numbers(20, 1);
    
    vector<double> numbers(20);
    
    cout << "Size: " << numbers.size() << endl;
    
    // numbers of elements inside the internal array
    // of a vector
    int capacity = numbers.capacity();
    
    cout << "Capacity: " << capacity << endl;
    
    // size = the actual number of elements that the vector is storing right now
    // capacity = the numbers of elements the internal array inside the vector can handle
    
    for (int i = 0; i < 1000; i++) {
        
        if (numbers.capacity() != capacity) {
            cout << "Index: " << i << endl;
            capacity = numbers.capacity();
            cout << "New Capacity: " << capacity << endl;
        }
        
        numbers.push_back(i);
    }
    
    // clear elements inside vector, this only impacts the size() method
    numbers.clear();
    
    cout << "Final Capacity: " << numbers.capacity() << endl;
    cout << "Final Size: " << numbers.size() << endl;
    
    // this only impacts the size() method
    numbers.resize(20);
    
    cout << "Final Capacity: " << numbers.capacity() << endl;
    cout << "Final Size: " << numbers.size() << endl;
    
    // this only impacts the capacity() method
    numbers.reserve(1000000);
    
    cout << "Final Capacity: " << numbers.capacity() << endl;
    cout << "Final Size: " << numbers.size() << endl;
    
    return 0;
}