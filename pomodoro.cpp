#include <iostream>
#include <chrono>
#include <thread>

void printTime();

int main() {
    auto timer = std::chrono::steady_clock::now();  // initialize timer 
    auto increment = std::chrono::seconds(1);       // will print time each second

    std::cout << "\033[2J";
    while (true) {
        std::this_thread::sleep_until(timer += increment);
        printTime();
    }    
}

void printTime() {
    static int x = 0;
    std::cout << "\033[H";                          // moves cursor to beginning
    std::cout << x++ << std::endl;                  // std::endl to flush
}
