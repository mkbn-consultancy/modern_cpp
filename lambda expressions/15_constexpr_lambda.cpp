//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

int main(){

    auto f = [](int x, int y){
        return x+y;
    };
    std::cout<<f(2,3)<<std::endl;
}

//https://godbolt.org/z/eG3ad3 