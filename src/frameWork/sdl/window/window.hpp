#pragma once

#include "SDL2/SDL.h"
#include <string>

namespace framework {
    namespace window {
        class Window {
            private:
                uint32_t m_width;
                uint32_t m_height;
                std::string m_title;
                bool m_isClosed;
                SDL_Window* m_window;

            public:
                Window(uint32_t w, uint32_t h, std::string t);
                void pollEvents();
                void tick();
                inline SDL_Window* getWindow() {
                    return this->m_window;
                }
                bool isWindowClosed();
                ~Window();
        };
    }
}
