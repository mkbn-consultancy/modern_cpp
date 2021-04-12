//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <fstream>

//since C++14

int main(){
    int data{5};
    auto f = [y = data](int arg){ return y + arg;}(data);

    std::ofstream out{"output.txt"};
    auto write = [&out](int x){
        out<< x <<std::endl;
    };
}