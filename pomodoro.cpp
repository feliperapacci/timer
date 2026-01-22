#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

const int INTERVAL_TIME = 1;

template <class Rep, class Period>
void printTime(const std::chrono::duration<Rep, Period> &duration);
// std::chrono::seconds getTime();


int main() {
    
    // now & end are of type std::chrono::time_point<std::chrono::steady_clock>
    auto now = std::chrono::steady_clock::now();
    auto end = now + std::chrono::seconds{ 10 };

    // interval & time_remaining are of type std::chrono::duration<...>
    auto interval = std::chrono::seconds{ INTERVAL_TIME };
    auto time_remaining = end - now;


    std::cout << "\033[2J"; // clears screen

    
    while (time_remaining.count() >= 1){
        std::this_thread::sleep_until(now += interval);
        time_remaining = end - now;
        printTime(time_remaining);
    }    

    std::cout << "Done!\n";
}

template <class Rep, class Period>
void printTime(const std::chrono::duration<Rep, Period> &duration) {
    std::cout << "\033[H";                                  // moves cursor to beginning
    
#if __cplusplus >= 202002L                                  // this code for C++20 or later
    std::chrono::hh_mm_ss time { duration };
    std::cout << "C++20+\n";
    auto h = time.hours();
    auto m = time.minutes();
    auto s = time.seconds();

#else                                                       // this code for C++17 or previous
    std::cout << "C++17-\n";
    auto h = std::chrono::duration_cast<std::chrono::hours>(duration);
    auto m = std::chrono::duration_cast<std::chrono::minutes>(duration - h);
    auto s = std::chrono::duration_cast<std::chrono::seconds>(duration - h - m);
    
#endif
    std::cout << h.count() << ":" << m.count() << ":" << s.count() << std::endl;
}

/*std::chrono::duration getTime() {
    int minutes, seconds;

}*/
