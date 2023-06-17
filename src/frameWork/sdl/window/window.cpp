#include "window.hpp"
#include "../log/log.hpp"
#include "SDL_events.h"
#include "SDL_timer.h"

namespace framework {
    namespace window {
        Window::Window(uint32_t w, uint32_t h, std::string t) {
            this->m_width = w;
            this->m_height = h;
            this->m_title = t;
            this->m_isClosed = false;

            Log::sdlCode(SDL_Init(SDL_INIT_VIDEO));
            this->m_window = (SDL_Window*) Log::sdlPtr(SDL_CreateWindow(
                this->m_title.c_str(), 
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED,
                this->m_width,
                this->m_height,
                SDL_WINDOW_SHOWN
            ));
        }

        void Window::pollEvents() {
            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    this->m_isClosed = true;
                }
            }
        }

        void Window::tick() {
            SDL_Delay(1000 / 60);
        }

        bool Window::isWindowClosed() {
            return m_isClosed;
        }
        
        Window::~Window() {
            SDL_DestroyWindow(m_window);
        }
    }
}
