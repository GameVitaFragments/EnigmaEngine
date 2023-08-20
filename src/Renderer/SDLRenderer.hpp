#pragma once

#include "Renderer.hpp"
#include "../Window/SDLWindow.hpp"
// #include "src/Image/SDLImage.hpp"
#include <memory>
#include <vector>

namespace EE {

namespace _customDeleter {
    struct SDLWindowDestroyer {
        void operator()(SDL_Window* w) const {
            SDL_DestroyWindow(w);
        }
    };
    struct SDLRendererDestroyer {
        void operator()(SDL_Renderer* w) const {
            SDL_DestroyRenderer(w);
        }
    };
}

class SDLRenderer : public RENDERER {
    private:
        std::unique_ptr<SDL_Window, _customDeleter::SDLWindowDestroyer> m_window;
        std::unique_ptr<SDL_Renderer, _customDeleter::SDLRendererDestroyer> m_renderer;

    public:
        void init(WINDOW* win) override;
        void clearScreen() override;
        void loadImage(std::string name, std::string path) override;
        void drawAllImages() override;
        void* convertToSurface(std::unique_ptr<IMAGE>& img);  
        ~SDLRenderer() override;
};
}
