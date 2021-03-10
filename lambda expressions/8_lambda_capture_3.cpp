#include <iostream>

class Example{
public:
    Example() : _var{10} {}
    void func()
    {
        [=]() { std::cout << "inside [=]: " << _var << std::endl; }();
        [&]() { std::cout << "inside [&]: " << _var << std::endl; }(); 
        [this]() {std::cout<< "inside [this]: " << _var <<std::endl; }();
        [tmp = *this]() {std::cout<<"inside [temp=*this]: " << tmp._var <<std::endl; }(); //C++14
        [*this]() mutable { ++_var; 
                            std::cout<< "inside [*this]: " << _var <<std::endl; 
                          }();  //C++17
    }
public:
    int _var;
};

int main()
{
    Example e;
    e.func();
    std::cout<<e._var<<std::endl;
}
