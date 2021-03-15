#include <iostream>

struct A
{
    A() {std::cout<<"default ctor\n";}
    A(int) {std::cout<<"A(int) ctor\n";}
    A(const A&) {std::cout<<"copy ctor";}
    A(A&&) {std::cout<<"move ctor\n";}
    ~A(){std::cout<<"dtor\n";}
};

A combine(int x, int  y)
{
    // A a(x+y);
    return A(x+y);
}

int main()
{
    // A obj = 3;  //A(3) - temporary object
                //move constructor

    A obj = combine(2,3);
}