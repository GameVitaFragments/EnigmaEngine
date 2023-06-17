#include <iostream>

#include "src/frameWork/frameWork.hpp"

int main() {
    graphics::Window win = graphics::Window(1280, 720, "Hello");
    //graphics::Renderer rend = graphics::Renderer();

    while (!win.isWindowClosed()) {
        win.update();
    }
}
