#pragma once
#include <SDL2/SDL.h>

#include "../window/window.hpp"

namespace framework {
    namespace renderer {
        class Renderer {
            private:
                SDL_Window* m_window;
                SDL_Renderer* m_renderer;
            public:
                Renderer(framework::window::Window w);
                void clearScreen();
                ~Renderer();
        };
    }
}
