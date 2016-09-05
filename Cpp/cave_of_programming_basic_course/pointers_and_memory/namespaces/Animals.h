#ifndef ANIMALS_H_
#define ANIMALS_H_

#include <iostream>

using namespace std;

namespace animals {
    
    const string CATNAME = "Freddy";

    class Cat {
    public:
        Cat();
        virtual ~Cat();
        void speak();
    };
    
}

#endif