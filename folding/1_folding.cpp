#include <iostream>

auto sum(){
    return 0;
}

template<typename T, typename...Args>
auto sum(T a, Args...args)
{
    return a + sum(args...);
}

//C++17 Fold Expression:
template<typename...Args>
auto sum17_right_fold(Args...args){
    return (args + ...);
}

template<typename...Args>
auto sum17_left_fold(Args...args){
    return (... + args);
}

template<typename...Args>
auto sum(Args...args)
{
    return (args + ... + 0);
}

template<typename...Args>
bool isAllPositive(Args...args){
    return ((args>0)&&...);
}
int main()
{
    auto result = sum17_right_fold(1,2,3,4,5,6);
    std::cout<<"result is: "<<result<<std::endl;

    result = sum();
    std::cout<<"result is: "<<result<<std::endl;

    std::cout<<"are all positive? "<<std::boolalpha
                    << isAllPositive(1,2,3,5,4)<<std::endl;
    std::cout<<"are all positive? "<<std::boolalpha
                    << isAllPositive(1,2,-3,5,-4)<<std::endl;
}