//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <future>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;   //for using ms (since c++14)

struct A{ ~A(){std::cout<<"[~A]\n";}};

void printNumbers()
{
    A a;
    std::cout<<"--printNumbers started--\n";
    for(int i=0; i<10; i++){
        std::this_thread::sleep_for(200ms);
        std::cout<<i<<"..";
    }
    std::cout<<std::endl;
    std::cout<<"--printNumbers finished--\n";
}

int getNum(){
    std::this_thread::sleep_for(2s);
    return 5;
}


//try to remove the auto res=
int main()
{
    A a;
    std::cout<<"--main started--\n";
    // auto res = std::async(std::launch::async , printNumbers); //must assign the return value for sync
    auto res = std::async(getNum); //res = std::future<int>
    
    int val = res.get();
    std::cout<<"val = "<<val<<std::endl;

    std::cout<<"--main finished--\n";
}