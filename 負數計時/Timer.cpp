#include "Timer.h"
#include <iostream>

Timer::Timer(const std::string& name)
    : name_(name), elapsed_(std::chrono::duration<double>(0)), running_(false), paused_(false) {}

void Timer::start() {
    if (!running_) {
        start_time_ = std::chrono::steady_clock::now();
        running_ = true;
        paused_ = false;
    }
}

void Timer::pause() {
    if (running_ && !paused_) {
        pause_time_ = std::chrono::steady_clock::now();
        elapsed_ += pause_time_ - start_time_;
        paused_ = true;
    }
}

void Timer::resume() {
    if (running_ && paused_) {
        start_time_ = std::chrono::steady_clock::now();
        paused_ = false;
    }
}

void Timer::reset() {
    running_ = false;
    paused_ = false;
    elapsed_ = std::chrono::duration<double>(0);
}

double Timer::elapsed() const {
    if (running_) {
        if (paused_) {
            return elapsed_.count();
        } else {
            return (std::chrono::steady_clock::now() - start_time_ + elapsed_).count();
        }
    }
    return elapsed_.count();
}

std::string Timer::name() const {
    return name_;
}
