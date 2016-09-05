//
//  Swarm.cpp
//  ParticleEffects
//
//  Created by Daniel Parreira on 2016-09-02.
//  Copyright © 2016 Daniel Parreira. All rights reserved.
//

#include "Swarm.hpp"

namespace particlesystem {

    Swarm::Swarm(): lastTime(0) {
        m_pParticles = new Particle[NPARTICLES];
    }
    
    Swarm::~Swarm() {
        delete [] m_pParticles;
    }
    
    void Swarm::update(int elapsed) {
        
        int interval = elapsed - lastTime;
        
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            m_pParticles[i].update(interval);
        }
        
        lastTime = elapsed;
    }
    
}