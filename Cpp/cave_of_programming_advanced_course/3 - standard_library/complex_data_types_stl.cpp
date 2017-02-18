#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {

    map<string, vector<int> > scores;
    
    scores["Daniel"].push_back(10);
    scores["Daniel"].push_back(100);
    scores["Daniel"].push_back(200);
    
    scores["Pedro"].push_back(20);
    scores["Marc"].push_back(30);
    
    for (map<string, vector<int> >::iterator it = scores.begin(); it != scores.end(); it++) {
        
        const vector<int> &points = it->second;
        
        for (vector<int>::const_iterator itV = points.begin(); itV != points.end(); itV++) {
            cout << it->first << ": " << *itV << endl;
        }
    }
    
    return 0;
}