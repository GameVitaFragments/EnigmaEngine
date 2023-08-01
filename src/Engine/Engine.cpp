#include "Engine.hpp"

#include "../Window/SDLWindow.hpp"
#include "../Renderer/SDLRenderer.hpp"
#include "../Image/SDLImage.hpp"
#include <vector>

Engine::Engine(RendererBackend rend, unsigned int w, unsigned int h, std::string t) {
    Engine::rb = rend;
    if (Engine::rb == SDL) {
        m_window = new SDLWindow(w, h, t);
        m_renderer = new SDLRenderer();
    }
}

void Engine::InitRenderer() {
    this->m_renderer->init(this->m_window);
}

void Engine::update() {
    this->m_window->pollEvents();
    this->m_renderer->clearScreen();

    this->m_renderer->drawAllImages();
}

void Engine::loadImage(std::string name, std::string path) {
    this->m_renderer->loadImage(name, path);
}

Engine::~Engine() {
    delete this->m_window;
    delete this->m_renderer;
}
