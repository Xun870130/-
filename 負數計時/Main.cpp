#include "Timer.h"
#include <iostream>
#include <thread>
#include <vector>
int main() {
    std::vector<Timer> timers = {
        Timer("Timer1"),
        Timer("Timer2")
    };

    while (true) {
        std::cout << "Available commands:\n";
        std::cout << "1: Start Timer1\n";
        std::cout << "2: Pause Timer1\n";
        std::cout << "3: Resume Timer1\n";
        std::cout << "4: Reset Timer1\n";
        std::cout << "5: Start Timer2\n";
        std::cout << "6: Pause Timer2\n";
        std::cout << "7: Resume Timer2\n";
        std::cout << "8: Reset Timer2\n";
        std::cout << "9: Show elapsed time\n";
        std::cout << "0: Exit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                timers[0].start();
                std::cout << "Timer1 started.\n";
                break;
            case 2:
                timers[0].pause();
                std::cout << "Timer1 paused.\n";
                break;
            case 3:
                timers[0].resume();
                std::cout << "Timer1 resumed.\n";
                break;
            case 4:
                timers[0].reset();
                std::cout << "Timer1 reset.\n";
                break;
            case 5:
                timers[1].start();
                std::cout << "Timer2 started.\n";
                break;
            case 6:
                timers[1].pause();
                std::cout << "Timer2 paused.\n";
                break;
            case 7:
                timers[1].resume();
                std::cout << "Timer2 resumed.\n";
                break;
            case 8:
                timers[1].reset();
                std::cout << "Timer2 reset.\n";
                break;
            case 9:
                std::cout << "Elapsed time for Timer1: " << timers[0].elapsed() << " seconds\n";
                std::cout << "Elapsed time for Timer2: " << timers[1].elapsed() << " seconds\n";
                break;
            case 0:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}