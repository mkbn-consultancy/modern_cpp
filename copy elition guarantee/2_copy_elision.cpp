#include <iostream>

//compile with flag -fno-elide-constructors
class MyClass
{
public:
    MyClass() {std::cout<<"[MyClass] default ctor\n";}
    MyClass(int x) {std::cout<<"[MyClass] conversion(int) ctor\n";}
    MyClass(const MyClass&) {std::cout<<"[MyClass] copy ctor\n";}
    MyClass(MyClass&&) {std::cout<<"[MyClass] move ctor\n";}
    ~MyClass() {std::cout<<"[MyClass] dtor\n";}
};

int main()
{
    std::cout<<"[main] stating main\n";

    MyClass m = 3;

    std::cout<<"[main] ending main\n";
}
