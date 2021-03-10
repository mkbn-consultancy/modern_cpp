#include <iostream>

struct A{
    constexpr A(int x) {}
    A(){ std::cout<<"inside non-constexpr constructor A()\n"; }
};

int main(){
    constexpr A a1(3);

    A a2(3);
}