#include "Timer.hpp"

namespace Utility {
    Timer::Timer(std::string name) {
        m_name = name;
        m_hasStoppedOnce = false;
        this->reset();
    }

    void Timer::reset() {
        this->stop();
        m_hasStoppedOnce = false;
        m_start = std::chrono::high_resolution_clock::now();
    }

    void Timer::stop() {
        m_hasStoppedOnce = true;
        auto end = std::chrono::high_resolution_clock::now();
        auto startTime = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
        auto endTime = std::chrono::time_point_cast<std::chrono::microseconds>(end).time_since_epoch().count();
        m_time_micro = endTime - startTime;
        m_time_milli = m_time_micro * 0.001;

    }

    void Timer::printTimerDuration() {
        if (!m_hasStoppedOnce) {
            std::cout << "[" << m_name << " Timer]" << " Stop the timer first before you call print method\n";
            return;
        }
        std::cout << "[" << m_name << " Timer] Took " << getTimeMilli() << "s \n";
    }

    Timer::~Timer() {
        this->stop();
    }
}

