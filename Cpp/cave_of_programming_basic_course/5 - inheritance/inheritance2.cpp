#include <iostream>

using namespace std;

class Frog {
private:
    string name;
    string getName() { return name; };
public:
    Frog(string name) : name(name) {  }
    void getInfo() { cout << getName() << endl; };
};

int main(void) {
    
    Frog frog("Freddy");
    frog.getInfo();
    
    return 0;
}