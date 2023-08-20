#include "src/Engine/Engine.hpp"
#include "src/Utility/Timer/Timer.hpp"
#include "Fraglog.hpp"

int main() {
    FragLog log;
    log.write("Frag Logger Has Been Initialized Successfully");
    Utility::Timer timer("Global");

    EE::Engine* e = new EE::Engine(EE::SDL, 1280, 720, "ENGINE");
    e->InitRenderer();

    timer.reset();

    e->loadImage("apple", "assets/apple.jpg");

    timer.stop();
    timer.printTimerDuration();

    while (!e->isWindowClosed()) {
        e->update();
    }
}
