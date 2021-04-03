#include <iostream>
#include <chrono>
#include <thread>
 
void independentThread(){
    std::cout << "starting concurrent thread...";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "concurrent thread done!\n";
}

int main() 
{
    std::cout<<"---main thread---\n";
    std::cout << "creating a thread execution...\n";
    std::thread t(independentThread);
    // t.join();
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "--end main thread---\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}