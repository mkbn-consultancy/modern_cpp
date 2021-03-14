#include <iostream>

int main()
{
    int x;
    std::cin>>x;
    auto  f = [x](int y){return y%x;};
    f(10);
}