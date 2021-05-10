//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <future>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;   //for using ms (since c++14)

int factorial(int num){
    int result = 1;
    for(int i=2; i<=num; i++){
        std::cout<<"*";
        std::this_thread::sleep_for(300ms);
        result*=i;
    }
    return result;
}

int main()
{
    std::cout<<"--main started--\n";

    std::future<int> res = std::async(factorial,10); 

    // std::this_thread::sleep_for(1s);
    std::cout<<"--main is waiting for the task--\n";

    //try to comment the res.wait() and see the output
    if(res.valid()){
        res.wait();
        std::cout<<"--main is getting the return value--\n";
        auto value = res.get();
        std::cout<<"return value is: "<<value<<std::endl;
    }

    std::cout<<"--main finished--\n";
}