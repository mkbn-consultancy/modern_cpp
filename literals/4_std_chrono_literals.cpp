#include <iostream>

#include <chrono>

using namespace std::chrono_literals;

 
int main()
{
    auto halfmin = 30s;
    std::cout << "half a minute is " << halfmin.count() << " seconds\n"
              << "a minute and a second is " << (1min + 1s).count() << " seconds\n";

   auto d1 = 250us;
    std::chrono::microseconds d2 = 1ms;
    std::cout << "250us = " << d1.count() << " microseconds\n"
              << "1ms = " << d2.count() << " microseconds\n";


    auto lesson = 45min;
    auto halfmin2 = 0.5min;
    std::cout << "one lesson is " << lesson.count() << " minutes\n"
              << "half a minute is " << halfmin2.count() << " minutes\n";
}