//
//  Screen.cpp
//  ParticleEffects
//
//  Created by Daniel Parreira on 2016-08-30.
//  Copyright © 2016 Daniel Parreira. All rights reserved.
//
#include "Screen.hpp"

namespace particlesystem {
    
    Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {
    }

    
    bool Screen::init() {
        
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        }
        
        m_window = SDL_CreateWindow("Particle Fire Explosion.",
                                              SDL_WINDOWPOS_UNDEFINED,
                                              SDL_WINDOWPOS_UNDEFINED,
                                              SCREEN_WIDTH,
                                              SCREEN_HEIGHT,
                                              SDL_WINDOW_SHOWN);
        
        // Check that the window was successfully created
        if (m_window == NULL) {
            // In the case that the window could not be made...
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }
        
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        
        if (m_renderer == NULL) {
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }
        
        // Uses 1 byte to each pixel -> SDL_PIXELFORMAT_RGBA8888
        // 256 options --> 0-255
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,  SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
        
        if (m_texture == NULL) {
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }
        
        // buffer => pixels
        m_buffer1 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT]; //();
        m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        
        // Change every byte of buffer to 255 (0xFF)
        //memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
        // Also check std::fill
        std::fill(m_buffer1, m_buffer1+(SCREEN_WIDTH*SCREEN_HEIGHT), 0);
        std::fill(m_buffer2, m_buffer2+(SCREEN_WIDTH*SCREEN_HEIGHT), 0);
        
        // An int contains 4 bytes. we use each byte for a color
        // red, green, blue, and alpha -> SDL_PIXELFORMAT_RGBA8888
        // for (int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
            // buffer[i] = 0xFFFF00FF;
            // 0xFF0000FF --> red
            // 0x00FF00FF --> green
            // 0x0000FFFF --> blue
            // 0xFFFF00FF --> red + green = yellow
        //}
        
        return true;
    }
    
    void Screen::boxBlur() {
        // Swap the buffers, so pixel is in m_buffer2 and we are drawing to m_buffer1.
        Uint32 *temp = m_buffer1;
        m_buffer1 = m_buffer2;
        m_buffer2 = temp;
        
        for(int y=0; y<SCREEN_HEIGHT; y++) {
            for(int x=0; x<SCREEN_WIDTH; x++) {
                
                /*
                 * 0 0 0
                 * 0 1 0
                 * 0 0 0
                 */
                
                int redTotal=0;
                int greenTotal=0;
                int blueTotal=0;
                
                for(int row=-1; row<=1; row++) {
                    for(int col=-1; col<=1; col++) {
                        int currentX = x + col;
                        int currentY = y + row;
                        
                        if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
                            Uint32 color = m_buffer2[currentY*SCREEN_WIDTH + currentX];
                            
                            Uint8 red = color >> 24;
                            Uint8 green = color >> 16;
                            Uint8 blue = color >> 8;
                            
                            redTotal += red;
                            greenTotal += green;
                            blueTotal += blue;
                        }
                    }
                }
                
                Uint8 red = redTotal/9;
                Uint8 green = greenTotal/9;
                Uint8 blue = blueTotal/9;
                
                setPixel(x, y, red, green, blue);
            }
        }
    }

    
    void Screen::update() {
        // last param is: the number of bytes in a row of pixel data, including padding between lines
        SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH*sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
    }
    
    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
        
        if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
            return;
        }
        
        Uint32 color = 0;
        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF; // alpha
        
        // (y * SCREEN_WIDTH) will move the row
        // x will move to the position in the row
        m_buffer1[(y * SCREEN_WIDTH) + x] = color;
    }

    bool Screen::processEvents(){
        SDL_Event event;
        
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
        }
        return true;
    }
    
    void Screen::close() {
        // Close and destroy the window
        delete[] m_buffer1;
        delete[] m_buffer2;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

}
