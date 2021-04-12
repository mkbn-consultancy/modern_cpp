//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <type_traits>

class MyClass {};

int main() 
{
    std::cout << "MyClass is floating point? \t" << std::boolalpha << std::is_floating_point<MyClass>::value << '\n';
    std::cout << "float is floating point? \t" << std::boolalpha << std::is_floating_point<float>::value << '\n';
    std::cout << "int is floating point? \t\t" << std::boolalpha << std::is_floating_point<int>::value << '\n';
}
