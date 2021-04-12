//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <thread>
#include <future>
#include <vector>
#include <numeric>
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

int main()
{
    std::cout<<"\n----------------------------------\n";

    //create a task that will return an array with the numbers 1,...,25
    std::cout<<"[main]: creating the task for creating the array...\n";
 
    std::future<std::vector<int>> resVec = std::async(std::launch::async, [startArg=1](){
        std::cout<<"[TASK id "<<std::this_thread::get_id()<<"]: starting to fill the array...\n";
        std::vector<int> numbers(25);
        std::iota(numbers.begin(), numbers.end(), startArg);
        std::this_thread::sleep_for(2s);
        return numbers;
    });
        
    std::cout<<"[main]: creating the task for sum the array...\n";

    std::promise<std::vector<int>> vecProms;
    std::future<int> res = std::async(std::launch::async, [](std::promise<std::vector<int>>& vec){
        std::cout<<"[TASK id "<<std::this_thread::get_id()<<"]: wait for promise to start working...\n";
            auto vecFuture = vec.get_future();
            auto vecToSum = vecFuture.get();
            std::cout<<"[TASK id "<<std::this_thread::get_id()<<"]: got it!\n";
            int sum = 0;
            for(auto x : vecToSum){
            std::this_thread::sleep_for(200ms);
               std::cout<<"*";
                sum += x;
            }
            
            // auto sum = std::accumulate(std::begin(vecToSum), std::end(vecToSum),0);

            std::cout<<std::endl;
            return sum;
        }, std::ref(vecProms));

    std::this_thread::sleep_for(5s);
    std::cout<<"[main]: set data to promise...\n";

    vecProms.set_value(resVec.get());

    if(res.valid()){
        auto sum = res.get();
        std::cout<<"sum of array is: "<<sum<<std::endl;
    }

    std::cout<<"\n----------------------------------\n";
}