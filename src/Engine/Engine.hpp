#pragma once

#include "../Window/Window.hpp"
#include "../Renderer/Renderer.hpp"
#include "../Image/Image.hpp"

enum RendererBackend {
    SDL,
    OPENGL,
    VULKAN,
    WEBGPU
};

class Engine {
    private:
        WINDOW* m_window;
        RENDERER* m_renderer;

        inline static RendererBackend rb;
    public:

        Engine(RendererBackend rend, unsigned int w, unsigned int h, std::string t);

        void InitWindow(unsigned int w, unsigned int h, std::string t);
        void InitRenderer();
        void update();
        void loadImage(std::string name, std::string path);
        inline bool isWindowClosed() { return this->m_window->isWindowCLosed(); }

        ~Engine();
};
