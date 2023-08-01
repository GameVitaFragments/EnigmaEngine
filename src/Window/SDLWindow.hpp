#pragma once

#include "Window.hpp"
#include <SDL2/SDL.h>

class SDLWindow : public WINDOW {
    private:
        SDL_Window* m_window;
    public:
        SDLWindow(unsigned int w, unsigned int h, std::string t);
        void init(unsigned int w, unsigned int h, std::string t) override;
        void pollEvents() override;
        inline void* getWindow() override { return m_window; }
        ~SDLWindow();
};
