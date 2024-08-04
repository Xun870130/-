#include <iostream>
#include <chrono>
#include <thread>
class Countdown {
private:
    std::chrono::steady_clock::time_point start_time_;
    std::chrono::seconds duration_;
    bool running_;

public:
    Countdown() : start_time_(), duration_(0), running_(false) {}

    void start(int seconds) {
        duration_ = std::chrono::seconds(seconds);
        start_time_ = std::chrono::steady_clock::now();
        running_ = true;
    }

    void stop() {
        running_ = false;
    }

    int remaining() {
        if (!running_) return 0;

        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start_time_);
        int remaining_time = std::chrono::duration_cast<std::chrono::seconds>(duration_ - elapsed).count();
        return (remaining_time > 0) ? remaining_time : 0;
    }

    bool is_running() {
        return running_;
    }
};

int main() {
    Countdown countdown;
    int seconds;
    std::cout << "Enter countdown duration in seconds: ";
    std::cin >> seconds;

    countdown.start(seconds);
    while (countdown.is_running()) {
        int remaining = countdown.remaining();
        std::cout << "Remaining time: " << remaining << " seconds\r";
        std::cout.flush();
        if (remaining == 0) {
            countdown.stop();
            std::cout << "\nCountdown finished!" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Adjust as needed
    }
    return 0;
}
