#pragma once

#include <chrono>
#include <iostream>

namespace Utility {
    class Timer {
        private:
            std::chrono::time_point<std::chrono::high_resolution_clock> m_start;

            uint64_t m_time_micro;
            uint64_t m_time_milli;
            std::string m_name;

            bool m_hasStoppedOnce;


        public:
            Timer(std::string name);
            void reset();
            void printTimerDuration();
            void stop();
            inline uint64_t getTimeMilli() { return m_time_milli; }
            inline uint64_t getTimeMicro() { return m_time_micro; }
            ~Timer();
    };
}

