#include <iostream>

void func(int& x){
    std::cout<<"inside func(int&)\n";
}

void func(int&& x){ //refernce to r-values (temp, literals)
    std::cout<<"inside func(int&&)\n";
    x++;
}

// void func(const int& x){
//     std::cout<<"inside func(const int&)\n";
// }

int main()
{
    int x = 3;
    const int y = 4;

    func(x);
    func(y);
    func(3);
}