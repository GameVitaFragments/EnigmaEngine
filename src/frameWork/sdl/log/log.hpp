#pragma once

#include <iostream>

class Log {
    public:
        static int sdlCode(int code);
        static void* sdlPtr(void* ptr);

        static void console(std::string str);
};
