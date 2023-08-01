#include "SDLRenderer.hpp"

#include "src/Image/SDLImage.hpp"

#include <cstdlib>
#include <memory>

void SDLRenderer::init(WINDOW* win) {
    this->m_window = (SDL_Window*)win->getWindow();
    this->m_renderer = SDL_CreateRenderer(
        this->m_window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
}

void SDLRenderer::loadImage(std::string name, std::string path) {
    //this->m_images.push_back(new SDLImage(path));
    this->m_images[name] = std::make_unique<SDLImage>(path);
}

void SDLRenderer::clearScreen() {
    SDL_SetRenderDrawColor(this->m_renderer, 100, 0, 0, 255);
    SDL_RenderClear(this->m_renderer);
}

void SDLRenderer::drawAllImages() {
    for (const auto& i : this->m_images) {
        const auto& img = i.second;
        SDL_Surface* surf = (SDL_Surface*)img->convertToSurface();
        if (surf) {
            SDL_Texture* tex = SDL_CreateTextureFromSurface(this->m_renderer, surf);
            SDL_Rect rect;
            rect.x = 0;
            rect.y = 0;
            rect.w = img->getWidth();
            rect.h = img->getHeight();


            SDL_RenderCopy(this->m_renderer, tex, NULL, &rect);
            SDL_FreeSurface(surf);
            SDL_DestroyTexture(tex);
            //std::cout << SDL_GetError() << std::endl;
        }
    }
    SDL_RenderPresent(this->m_renderer);
}

SDLRenderer::~SDLRenderer() {
    SDL_DestroyRenderer(this->m_renderer);
    SDL_Quit();
}
