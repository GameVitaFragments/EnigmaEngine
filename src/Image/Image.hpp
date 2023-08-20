#pragma once

#include <string>
#include <vector>
#include <cstdint>

#include "stb_image/stb_image.h"

// forward declaration of Renderer to avoid circular dependency

namespace EE {

class Renderer;

class IMAGE {
    public:
        int32_t m_width;
        int32_t m_height;
        int32_t m_channels;

        unsigned char* m_data;
        std::string m_path;
        Renderer* m_renderer;

        IMAGE(std::string _path);

        inline int32_t getWidth() { return m_width; }
        inline int32_t getHeight() { return m_height; }

        // virtual void* convertToSurface() = 0;

        virtual ~IMAGE();
};


}
