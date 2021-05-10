//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <future>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;   //for using ms (since c++14)

int factorial(int num)
{
    int result = 1;
    for(int i=2; i<=num; i++){
        std::cout<<".";
        std::this_thread::sleep_for(300ms);
        result*=i;
    }
    return result;
}

int main()
{
    std::cout<<"--main started--\n";
    std::future<int> res = std::async(factorial,10); 

    std::this_thread::sleep_for(1s);
    
    std::cout<<"--main is waiting for the task--\n";
    auto value = res.get();
    //now the shared stat inside the future is destroyed
    // value = res.get();  //will throw an exception

    if(res.valid()){
        std::cout<<"getting value again?\n";
        value = res.get();
    }

    std::cout<<"return value is: "<<value<<std::endl;
    std::cout<<"--main finished--\n";
}