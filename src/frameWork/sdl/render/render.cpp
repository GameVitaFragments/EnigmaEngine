#include "render.hpp"
#include "SDL_render.h"

namespace framework {
    namespace renderer {
        Renderer::Renderer(framework::window::Window w) {
            this->m_window = w.getWindow();
            this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED);
        }

        void Renderer::clearScreen() {
            SDL_RenderClear(this->m_renderer);
        }

        Renderer::~Renderer() {
            SDL_DestroyRenderer(this->m_renderer);
        }
    }
}
