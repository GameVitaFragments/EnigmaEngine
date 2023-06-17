#pragma once

#include "sdl/import.hpp"

#include "src/frameWork/sdl/window/window.hpp"

namespace graphics {
    class Window {
        private:
            uint32_t m_width;
            uint32_t m_height;
            std::string m_title;

            bool m_isClosed;
            framework::window::Window m_window;

        public:
            Window(uint32_t w, uint32_t h, std::string t);
            bool isWindowClosed();
            void update();
            inline framework::window::Window getWindow() {
                return m_window;
            }
            ~Window();
    };

    class Renderer {
        private:
            framework::renderer::Renderer m_renderer;
            graphics::Window m_window;

        public:
            Renderer(graphics::Window win);
            void update();
            ~Renderer();
    };
}
