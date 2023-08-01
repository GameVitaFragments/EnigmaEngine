#pragma once

#include <cstdint>
#include <iostream>

class WINDOW {
    public:
        unsigned int m_width;
        unsigned int m_height;
        std::string m_title;
        bool m_isClosed;

        uint64_t m_FPS;

        WINDOW(unsigned int w, unsigned int h, std::string t) : m_width(w) , m_height(h), m_title(t) {}
        virtual void init(unsigned int w, unsigned int h, std::string t) = 0;
        virtual void pollEvents() = 0;
        virtual void* getWindow() = 0;
        virtual ~WINDOW() {};

        inline bool isWindowCLosed() { return m_isClosed; };
};
