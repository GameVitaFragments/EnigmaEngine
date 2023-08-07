#include "Engine.hpp"

#include "../Window/SDLWindow.hpp"
#include "../Renderer/SDLRenderer.hpp"
#include "../Image/SDLImage.hpp"
#include <memory>
#include <vector>

namespace EE {


Engine::Engine(RendererBackend rend, unsigned int w, unsigned int h, std::string t) {
    Engine::rb = rend;
    if (Engine::rb == SDL) {
        m_window = std::make_unique<SDLWindow>(w, h, t);
        m_renderer = std::make_unique<SDLRenderer>();
    }
}

void Engine::InitRenderer() {
    this->m_renderer->init(this->m_window.get());
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

}

}
