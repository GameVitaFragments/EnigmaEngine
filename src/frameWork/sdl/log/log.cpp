#include "log.hpp"
#include "SDL_error.h"

int Log::sdlCode(int code) {
    if (code != 0) {
        std::cout << "[SDL Error] " << SDL_GetError() << std::endl;
    }
    return code;
}

void* Log::sdlPtr(void *ptr) {
    if (ptr == nullptr) {
        std::cout << "[SDL Error] " << SDL_GetError() << std::endl;
    }
    return ptr;
}

void Log::console(std::string str) {
    std::cout << "[ENGINE] " << str << std::endl;
}
