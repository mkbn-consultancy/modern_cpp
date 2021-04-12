//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

template<typename...Args>
auto sumBetween(int begin, int end, Args...args){
    return (((args>=begin && args<=end) ? args : 0) + ...);
}

int main()
{
    auto res = sumBetween(2,5,1,2,3,4,5,6,7,8,9);
    std::cout<<"result is: "<<res<<std::endl;
}