#pragma once

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

// forward declaration of IMAGE to avoid circular dependency
class IMAGE;
class WINDOW;

class RENDERER {
    public:
        // TODO: remove this line later
        //std::vector<IMAGE*> m_images;

        std::unordered_map<std::string, std::unique_ptr<IMAGE>> m_images;

        virtual void init(WINDOW* win) = 0;
        virtual void clearScreen() = 0;
        virtual void loadImage(std::string name, std::string path) = 0;
        virtual void drawAllImages() = 0;

        virtual ~RENDERER() {};
};
