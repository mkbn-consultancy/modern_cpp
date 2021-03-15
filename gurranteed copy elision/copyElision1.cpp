#include <iostream>

struct MyClass
{
  MyClass() {std::cout<<"default ctor\n";}
  MyClass(const MyClass&) {std::cout<<"copy ctor\n";}
};

MyClass f() {
    return MyClass();
}

int main()
{
  f();
}