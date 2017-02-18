#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool match(string test) {
    return test.size() == 3;
}

int count_if_my(string *start, string *end, bool (*match)(string test)) {
    
    int count = 0;
    for (string *i = start; i < end; i++) {
        if (match(*i)) {
            count++;
        }
    }
    
    return count;
}

int main() {

    vector<string> texts;
    texts.push_back("One");
    texts.push_back("Two");
    texts.push_back("Three");
    texts.push_back("Four");
    texts.push_back("Five");
    texts.push_back("Six");
    texts.push_back("Seven");
    texts.push_back("Eight");
    texts.push_back("Nine");
    
    cout << match("one") << endl;
    
    bool (*matchPtr)(string) = match;
    
    cout << count_if(texts.begin(), texts.end(), matchPtr)<< endl;
    // cout << count_if(texts.begin(), texts.end(), match)<< endl;
    
    cout << count_if_my(&texts[0], &texts[texts.size()], matchPtr)<< endl;
    
    return 0;
}