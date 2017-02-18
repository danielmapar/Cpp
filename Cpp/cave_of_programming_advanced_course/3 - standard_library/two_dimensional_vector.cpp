#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    
    // 3 vectors of 4 ints
    // (size, initialize with value)
    vector<vector<int> > grid(3, vector<int>(4, 1));
    
    grid[0].push_back(1000);
    
    for (int row = 0; row < grid.size(); row++) {
        for (int column = 0; column < grid[row].size(); column++) {
            cout << grid[row][column] << flush;
        }
        cout << endl;
    }
    
    cout << "-----" << endl;
    
    /*
     A second characteristic of iterators is whether or not they can be used to modify the values held by their associated container. A constant iterator is one that can be used for access only, and cannot be used for modification. https://stdcxx.apache.org/doc/stdlibug/2-2.html
     */
    
    for (vector<vector<int> >::const_iterator itRow = grid.begin(); itRow != grid.end(); itRow++) {
        for (vector<int>::const_iterator itColumn = itRow->begin(); itColumn != itRow->end(); itColumn++) {
        
            cout << *itColumn << flush;
        }
        cout << endl;

    }
    
    /*
     We can actually change vector values using a non constant iterator
     
     for (vector<vector<int> >::iterator itRow = grid.begin(); itRow != grid.end(); itRow++) {
        for (vector<int>::iterator itColumn = itRow->begin(); itColumn != itRow->end(); itColumn++) {
            
            *itColumn = 5;
        }
    }*/

    
    return 0;
}