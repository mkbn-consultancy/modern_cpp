#include <iostream>
#include <string>

template<typename ...Args>
void foldPrint(Args&&... args) {
    (std::cout <<  ... <<  std::forward<Args>(args)) << std::endl;
}

int main()
{
    int x = 8;
    foldPrint("hello", ", ", 10, ", ", 90.0, ", ", x);
}