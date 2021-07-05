#include <iostream>

//compile with flag -fno-elide-constructors
class MyClass
{
public:
    MyClass() {std::cout<<"[MyClass] default ctor\n";}
    MyClass(const MyClass&) {std::cout<<"[MyClass] copy ctor\n";}
    MyClass(MyClass&&) {std::cout<<"[MyClass] move ctor\n";}
    ~MyClass() {std::cout<<"[MyClass] dtor\n";}
};

MyClass getObject()
{
    std::cout<<"[getObject] inside function\n";
    MyClass m;
    return m;
}

int main()
{
    std::cout<<"[main] stating main\n";
    MyClass m = getObject();
    std::cout<<"[main] ending main\n";
}
