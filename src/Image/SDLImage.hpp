#pragma once

#include "Image.hpp"
#include <SDL2/SDL.h>

class SDLImage : public IMAGE {
    public:
        SDLImage(std::string path);
        void* convertToSurface() override;
        ~SDLImage() override;
};
