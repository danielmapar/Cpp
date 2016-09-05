//
//  Screen.hpp
//  ParticleEffects
//
//  Created by Daniel Parreira on 2016-08-30.
//  Copyright © 2016 Daniel Parreira. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <SDL2/SDL.h>
#include <iostream>

namespace particlesystem {

    class Screen {
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
        
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer1;
        Uint32 *m_buffer2;
        
    public:
        Screen();
        bool init();
        void update();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        bool processEvents();
        void close();
        void boxBlur();
    };
    
}
#endif /* Screen_hpp */
