//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

template<typename T>
class MyClass
{
public:
    MyClass(const T& val) : _val{val}{}
    T _val;
};

MyClass(const char*) -> MyClass<std::string>;
MyClass(int) -> MyClass<long>;

int main()
{
    MyClass m{"hello"};
    MyClass k{5};

    std::cout<<typeid(m._val).name()<<std::endl;
    std::cout<<typeid(k._val).name()<<std::endl;
}
