#include <iostream> 
#include <typeinfo> 
void foo(int x) {
    std::cout << "foo(int)\n"; 
} 

void foo(double x) { 
    std::cout << "foo(double)\n"; 
} 

template<typename T> 
void foo(T* x) { 
    std::cout << "foo<" << typeid(T).name() << ">(T*)\n"; 
} 

int main() { 
    foo(42);
    foo(42.2);
    foo("abcdef");
    return 0;
}