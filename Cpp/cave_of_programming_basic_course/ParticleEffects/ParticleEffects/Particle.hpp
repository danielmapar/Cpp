//
//  Particle.hpp
//  ParticleEffects
//
//  Created by Daniel Parreira on 2016-09-02.
//  Copyright © 2016 Daniel Parreira. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

namespace particlesystem {
    
    // Struct is the same as a class, but instead of
    // members be private by default, they are public
    struct Particle {
        double m_x;
        double m_y;
        
    private:
        double m_speed;
        double m_direction;
        
    private:
        void init();
        
    public:
        Particle();
        virtual ~Particle();
        void update(int interval);
    };
    
}

#endif /* Particle_hpp */
