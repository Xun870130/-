#include <iostream>
#include <chrono>
#include <thread>
#include <string>

class Timer {
public:
    Timer() : start_time_(), elapsed_(std::chrono::duration<double>::zero()), running_(false) {}

    void start() {
        if (!running_) {
            start_time_ = std::chrono::steady_clock::now();
            running_ = true;
            std::cout << "Timer started.\n";
        }
    }

    void pause() {
        if (running_) {
            elapsed_ += std::chrono::steady_clock::now() - start_time_;
            running_ = false;
            std::cout << "Timer paused.\n";
        }
    }

    void resume() {
        if (!running_) {
            start_time_ = std::chrono::steady_clock::now();
            running_ = true;
            std::cout << "Timer resumed.\n";
        }
    }

    void reset() {
        elapsed_ = std::chrono::duration<double>::zero();
        if (running_) {
            start_time_ = std::chrono::steady_clock::now();
        }
        std::cout << "Timer reset.\n";
    }

    void displayElapsed() const {
        std::chrono::duration<double> elapsed_time = elapsed_;
        if (running_) {
            elapsed_time += std::chrono::steady_clock::now() - start_time_;
        }
        std::cout << "Elapsed time: " << elapsed_time.count() << " seconds\n";
    }

private:
    std::chrono::steady_clock::time_point start_time_;
    std::chrono::duration<double> elapsed_;
    bool running_;
};

int main() {
    Timer timer;
    std::string command;

    while (true) {
        std::cout << "Enter command (start, pause, resume, reset, display, exit): ";
        std::cin >> command;

        if (command == "start") {
            timer.start();
        } else if (command == "pause") {
            timer.pause();
        } else if (command == "resume") {
            timer.resume();
        } else if (command == "reset") {
            timer.reset();
        } else if (command == "display") {
            timer.displayElapsed();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command. Please try again.\n";
        }
    }

    return 0 ;
}
