#include "src/Engine/Engine.hpp"
#include "src/Utility/Timer/Timer.hpp"

int main() {

    Utility::Timer timer("Global");

    Engine e(SDL, 1280, 720, "ENGINE");
    e.InitRenderer();

    timer.reset();

    e.loadImage("apple", "../assets/apple.jpg");

    timer.stop();
    timer.printTimerDuration();

    while (!e.isWindowClosed()) {
        e.update();
    }
}
