#include <iostream>
#include <future>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;   //for using ms (since c++14)

void printNumbers()
{
    for(int i=0; i<10; i++){
        std::this_thread::sleep_for(200ms);
        std::cout<<i<<"..";
    }
    std::cout<<std::endl;
}

int main()
{
    auto res = std::async(printNumbers); //must assign the return value for sync
    std::cout<<"--main finished--\n";
}