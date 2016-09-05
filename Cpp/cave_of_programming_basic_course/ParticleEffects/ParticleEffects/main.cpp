#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "Screen.hpp"
#include <stdlib.h>
#include <time.h>
#include "Swarm.hpp"

using namespace std;
using namespace particlesystem;

int main() {
    
    srand(time(NULL));
    
    Screen screen;
    
    if (screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }
    
    Swarm swarm;
    
    while(true) {
        // Update particles
        // Draw particles
        
        // Gets the number of milliseconds since SDL library initialization.
        int elapsed = SDL_GetTicks();
        
        swarm.update(elapsed);
        
        unsigned char green = static_cast<unsigned char> ((1 + sin(elapsed * 0.001)) * 128); // 128 is half of 286
        unsigned char red = static_cast<unsigned char> ((1 + sin(elapsed * 0.002)) * 128); // 128 is half of 286
        unsigned char blue = static_cast<unsigned char> ((1 + sin(elapsed * 0.003)) * 128); // 128 is half of 286
        

        const Particle * const pParticles = swarm.getParticles();
        
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];
            
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;
            
            screen.setPixel(x, y, red, green, blue);
        }
        
        screen.boxBlur();
        
        // Draw the screen
        screen.update();
        
        // Check for messages/events
        if (screen.processEvents() == false) {
            break;
        }
    }
    
    screen.close();
    
    return 0;
}