#include "frameWork.hpp"
#include "src/frameWork/sdl/window/window.hpp"

namespace graphics {
    Window::Window(uint32_t w, uint32_t h, std::string t) : m_width(w), m_height(h), m_title(t), m_window(w, h, t){
        Log::console("Created Window");
    }

    void Window::update() {
        m_window.pollEvents();
        m_window.tick();
    }

    bool Window::isWindowClosed() {
        return m_window.isWindowClosed();
    }

    Window::~Window() {
        Log::console("Destroying Window");
    }

    Renderer::Renderer(graphics::Window win) : m_renderer(win.getWindow()), m_window(win) {

    }

    void Renderer::update() {
        this->m_renderer.clearScreen();
    }

    Renderer::~Renderer() {

    }
}
