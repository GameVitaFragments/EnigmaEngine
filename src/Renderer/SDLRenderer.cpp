#include "SDLRenderer.hpp"

#include "SDL_video.h"
// #include "src/Image/SDLImage.hpp"
#include "src/Image/Image.hpp"

#include <cstdlib>
#include <glm/glm.hpp>
#include <memory>

namespace EE {

void SDLRenderer::init(WINDOW* win) {
    this->m_window = std::unique_ptr<SDL_Window, _customDeleter::SDLWindowDestroyer>((SDL_Window*)win->getWindow());
    this->m_renderer = std::unique_ptr<SDL_Renderer, _customDeleter::SDLRendererDestroyer>(SDL_CreateRenderer(this->m_window.get(),-1,SDL_RENDERER_ACCELERATED));
}

void SDLRenderer::loadImage(std::string name, std::string path) {
    //this->m_images.push_back(new SDLImage(path));
   std::unique_ptr<Sprite> sp = std::make_unique<Sprite>();
   sp->init();
   sp->image = std::make_unique<IMAGE>(path);
   //Fix Later
   this->m_images[name] = std::move(sp);
}

void SDLRenderer::clearScreen() {
    SDL_SetRenderDrawColor(this->m_renderer.get(), 100, 0, 0, 255);
    SDL_RenderClear(this->m_renderer.get());
}

void SDLRenderer::drawAllImages() {
    for (const auto& i : this->m_images) {
         // const auto& img = i.second->image;
      auto& img = i.second->image;
      SDL_Surface* surf = (SDL_Surface*)convertToSurface(img);
      if (surf) {
            SDL_Texture* tex = SDL_CreateTextureFromSurface(this->m_renderer.get(), surf);
            SDL_Rect rect;
            rect.x = 0;
            rect.y = 0;
            rect.w = img->getWidth();
            rect.h = img->getHeight();


            SDL_RenderCopy(this->m_renderer.get(), tex, NULL, &rect);
            SDL_FreeSurface(surf);
            SDL_DestroyTexture(tex);
            //std::cout << SDL_GetError() << std::endl;
      }
    }
    SDL_RenderPresent(this->m_renderer.get());
}

SDLRenderer::~SDLRenderer() {
    // SDL_DestroyRenderer(this->m_renderer);
    SDL_Quit();
}




void* SDLRenderer::convertToSurface(std::unique_ptr<IMAGE>& img) {

   int pitch = img->m_width * img->m_channels;
   //pitch = (pitch + 3) & ~3;

   Uint32 _pixel_format;

   if (img->m_channels == 3) {
      _pixel_format = SDL_PIXELFORMAT_RGB24;
   } else if (img->m_channels == 4) {
      _pixel_format = SDL_PIXELFORMAT_RGBA32;
   } else {
      return nullptr;
   }

   SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(
      img->m_data, 
      img->m_width, 
      img->m_height, 
      img->m_channels * 8, 
      pitch, 
      _pixel_format
   );


   return surface;
}

}
