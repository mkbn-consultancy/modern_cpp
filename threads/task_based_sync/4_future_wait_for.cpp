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

void test1()
{
    std::cout<<"--main started--\n";

    std::future<int> res = std::async(std::launch::async,sumUntil,15); 

    std::this_thread::sleep_for(1s);
    // std::cout<<"--main is waiting for the task--\n";

    if(res.valid()){
        std::cout<<"--main is waiting for timeout--\n";
        auto status = res.wait_for(1s); //try with 5s
        std::cout<<"--main continues executed--\n";
        switch(status)
        {
            case std::future_status::deferred:
                //nothing to do. the task is running synchronously.
                std::cout<<"Task is sync. No wait is needed.\n";
                break;
            case std::future_status::ready:
                std::cout<<"The return value is ready...";
                break;
            case std::future_status::timeout:
                std::cout<<"The task is still running...\n";
                break;
        }
        auto value = res.get();
        std::cout<<"value is: "<<value<<std::endl;
    }

    std::cout<<"--main finished--\n";
}

void test2_wait_for_with_loop()
{
    std::cout<<"--main started--\n";

    std::future<int> res = std::async(std::launch::async,sumUntil,15); 

    std::this_thread::sleep_for(1s);
    // std::cout<<"--main is waiting for the task--\n";

    if(res.valid()){
        std::cout<<"--main is waiting for timeout--\n";
        auto status = res.wait_for(1s); //try with 5s
        std::cout<<"--main continues executed--\n";
        while(status == std::future_status::timeout){
            status = res.wait_for(1s);
            std::cout<<"The task is still running...";
        }
        auto value = res.get();
        std::cout<<"value is ready: "<<value<<std::endl;
    }

    std::cout<<"--main finished--\n";
}

int main()
{
    test2_wait_for_with_loop();
}