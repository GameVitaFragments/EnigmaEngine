#pragma once

#include "Renderer.hpp"
#include "../Window/SDLWindow.hpp"
#include "src/Image/SDLImage.hpp"
#include <vector>

class SDLRenderer : public RENDERER {
    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;

    public:
        void init(WINDOW* win) override;
        void clearScreen() override;
        void loadImage(std::string name, std::string path) override;
        void drawAllImages() override;
        ~SDLRenderer() override;
};
