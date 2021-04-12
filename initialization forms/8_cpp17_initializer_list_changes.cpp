//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <type_traits>

int main()
{
    //until C++17:
    auto a = {42};   // std::initializer_list<int>
    std::cout<<typeid(a).name()<<std::endl;
    auto b {42};     // std::initializer_list<int>  //CHECK: why it prints int when it should be initializer_list
    std::cout<<typeid(b).name()<<std::endl;
    auto c = {4, 2}; // std::initializer_list<int>
    std::cout<<typeid(c).name()<<std::endl;

    // //since C++17:
    // auto a = {42};   // copy init: std::initializer_list<int>
    // auto b {42};     // direct init: int
    // auto c = {4, 2}; // copy init: std::initializer_list<int>
    // //auto d {4, 2};   // direct init: compilation error
}