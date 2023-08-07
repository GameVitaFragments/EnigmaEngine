#include "Image.hpp"

namespace EE {

IMAGE::IMAGE(std::string _path) {
    this->m_path = _path;
    this->m_data = stbi_load(
            this->m_path.c_str(), 
            &m_width, 
            &m_height,
            &m_channels,
            0
            );
}

IMAGE::~IMAGE() {
    stbi_image_free(this->m_data);
}
}
