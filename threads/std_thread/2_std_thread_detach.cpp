//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <chrono>
#include <thread>
 
void independentThread(){
    std::cout << "[independentThread] starting concurrent thread...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "[independentThread] concurrent thread done!\n";
}

int main() 
{
    std::cout<<"---main thread---\n";
    std::cout << "[main] creating a thread execution...\n";
    std::thread t(independentThread);
    // t.join();
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "--end main thread---\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}