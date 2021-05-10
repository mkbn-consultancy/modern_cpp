//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <future>
#include <thread>   //for std::this_thread::sleep_for
using namespace std::chrono_literals;   //for using ms literal

int sumUntil(std::promise<int>& num){
    std::cout<<"[sumUntil] entering the sumUntil function...\n";
    std::future<int> val = num.get_future();
    auto count = val.get();

    std::cout<<"[sumUntil] got the data, task is start running...";
    int result = 0;
    for(int i=1; i<=count; i++){
        std::cout<<"*";
        std::this_thread::sleep_for(400ms);
        result+=i;
    }
    std::cout<<std::endl;
    return result;
}

int main()
{
    std::cout<<"------------------------\n";
    std::promise<int> num;
 
    std::cout<<"[main] create the task\n";
    std::future<int> res = std::async(std::launch::async, sumUntil, std::ref(num));
    
    //num is not ready test since we didn't call set_value yet
    //thus the task is blocked and wait

    std::this_thread::sleep_for(6s);

    std::cout<<"[main] set num in the promise\n";
    num.set_value(10);

    if(res.valid()){
        auto sum = res.get();
        std::cout<<"[main] task finised, sum is "<<sum<<std::endl;
    }
    std::cout<<"------------------------\n";
}