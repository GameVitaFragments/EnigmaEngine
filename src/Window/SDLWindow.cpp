#include "SDLWindow.hpp"
#include "SDL_timer.h"
#include <cstdint>


namespace EE {

SDLWindow::SDLWindow(unsigned int w, unsigned int h, std::string t) : WINDOW(w, h, t) {
    this->init(w, h, t);
}

void SDLWindow::init(unsigned int w, unsigned int h, std::string t) {
    m_isClosed = false;

    m_window = SDL_CreateWindow(
        m_title.c_str(), 
        0, 
        0, 
        m_width, 
        m_height, 
        SDL_WINDOW_RESIZABLE
    );
}

void SDLWindow::pollEvents() {

    SDL_Event _event;
    
    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT) {
            this->m_isClosed = true;
        }
    }
}

SDLWindow::~SDLWindow() {
    //SDL_DestroyWindow(this->m_window);
}
}
