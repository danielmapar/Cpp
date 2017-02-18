#include <iostream>
#include <list>

using namespace std;

int main(void) {
    
    list<int> numbers;
    
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    
    // Insert 100
    list<int>::iterator it = numbers.begin();
    cout << "First element: " <<  *it << endl;
    //*it = 100;
    it++;
    // 1, 100, 2, 3, 4, 5
    numbers.insert(it, 100);
    
    // Erase 100
    list<int>::iterator eraseIt = numbers.begin();
    eraseIt++;
    // 1, 100, 2, 3, 4, 5
    eraseIt = numbers.erase(eraseIt);
    // 1, 2, 3, 4, 5
    
    // As soon as you pass the iterator "eraseIt" to "erase", you invalidate it
    // since it is pointing to something that is gonna be removed from the list
    // However, numbers.erase will return a new iterator that points to the correct new number. In this case, number 2.
    cout << "New second element: " << *eraseIt << endl;
    
    cout << "-----" << endl;
    
    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    
    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        if (*it == 2) {
            numbers.insert(it, 1234);
        }
        
        if (*it == 1) {
            it = --(numbers.erase(it));
        }
    }
    
    cout << "-----" << endl;
    
    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    
    return 0;
}