#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <unordered_map>
#include <string>
#include <thread>
class Timer {
public:
    Timer(const std::string& name);

    void start();
    void pause();
    void resume();
    void reset();
    double elapsed() const;
    std::string name() const;

private:
    std::string name_;
    std::chrono::steady_clock::time_point start_time_;
    std::chrono::steady_clock::time_point pause_time_;
    std::chrono::duration<double> elapsed_;
    bool running_;
    bool paused_;
};

#endif // TIMER_H