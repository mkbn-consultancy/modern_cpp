#include <iostream>
#include <type_traits>

class MyClass {};

int main() 
{
    std::cout << std::is_floating_point<MyClass>::value << '\n';
    std::cout << std::is_floating_point<float>::value << '\n';
    std::cout << std::is_floating_point<int>::value << '\n';
}
