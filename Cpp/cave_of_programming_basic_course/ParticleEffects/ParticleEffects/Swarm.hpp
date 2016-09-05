//
//  Swarm.hpp
//  ParticleEffects
//
//  Created by Daniel Parreira on 2016-09-02.
//  Copyright © 2016 Daniel Parreira. All rights reserved.
//

#ifndef Swarm_hpp
#define Swarm_hpp

#include <stdio.h>
#include "Particle.hpp"

namespace particlesystem {
    
    class Swarm {
    public:
        const static int NPARTICLES = 100;
        
    private:
        Particle * m_pParticles;
        int lastTime;
        
    public:
        Swarm();
        virtual ~Swarm();
        void update(int elapsed);
        
        const Particle * const getParticles() { return m_pParticles; };
    };
}

#endif /* Swarm_hpp */
