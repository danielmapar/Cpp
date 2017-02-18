#include <iostream>
#include <map>

using namespace std;

int main(void) {

    multimap<int, string> lookup;
    
    // In this case we have 2 pairs with the same key
    // Both Daniel and Pedro have key 30
    // However, since this is a multimap, duplicate keys are fine
    lookup.insert(make_pair(30, "Daniel"));
    lookup.insert(make_pair(30, "Pedro"));
    lookup.insert(make_pair(40, "John"));
    lookup.insert(make_pair(50, "Fred"));
    lookup.insert(make_pair(60, "Rob"));
    lookup.insert(make_pair(70, "Norma"));

    for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    cout << "------------" << endl;
    // lookup.find(30) just finds a single entry with this key
    
    for (multimap<int, string>::iterator it = lookup.find(30); it != lookup.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    cout << "------------" << endl;
    
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> find = lookup.equal_range(30);
    
    // find.second - is off the end of the map.. it is like xyz.end()
    for (multimap<int, string>::iterator it = find.first; it != find.second; it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    cout << "------------" << endl;
    
    auto find11 = lookup.equal_range(30);
    
    // find.second - is off the end of the map.. it is like xyz.end()
    for (auto it = find11.first; it != find11.second; it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}