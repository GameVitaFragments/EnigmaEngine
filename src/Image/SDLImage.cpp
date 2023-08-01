#include "SDLImage.hpp"

#include "stb_image/stb_image.h"
#include <cstdlib>

SDLImage::SDLImage(std::string path) : IMAGE(path) {}

void* SDLImage::convertToSurface() {

    int pitch = m_width * m_channels;
    //pitch = (pitch + 3) & ~3;

    Uint32 _pixel_format;

    if (m_channels == 3) {
        _pixel_format = SDL_PIXELFORMAT_RGB24;
    } else if (m_channels == 4) {
        _pixel_format = SDL_PIXELFORMAT_RGBA32;
    } else {
        return nullptr;
    }

    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(
            this->m_data, 
            this->m_width, 
            this->m_height, 
            this->m_channels * 8, 
            pitch, 
            _pixel_format
        );


    return surface;
}

SDLImage::~SDLImage() {
    stbi_image_free(this->m_data);
}
