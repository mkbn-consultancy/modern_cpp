//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <future>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;   //for using ms (since c++14)

int sumUntil(int num){
    int result = 0;
    for(int i=1; i<=num; i++){
        std::cout<<"*";
        std::this_thread::sleep_for(400ms);
        result+=i;
    }
    return result;
}

void test_wait_until_with_loop()
{
    std::cout<<"--main started--\n";

    std::future<int> res = std::async(std::launch::async,sumUntil,15); 

    std::this_thread::sleep_for(1s);
    // std::cout<<"--main is waiting for the task--\n";

    if(res.valid()){
        std::cout<<"--main is waiting for timeout--\n";
        auto timePoint = std::chrono::system_clock::now();
        // timePoint += 3s;
        // auto status = res.wait_until(timePoint); 
        std::cout<<"--main continues executed--\n";
        std::future_status status;
        
        do{
            timePoint += 1s;
            status = res.wait_until(timePoint);
            std::cout<<"The task is still running...";
        }while(status == std::future_status::timeout);
        
        auto value = res.get();
        std::cout<<"value is ready: "<<value<<std::endl;
    }

    std::cout<<"--main finished--\n";
}

int main()
{
    test_wait_until_with_loop();
}