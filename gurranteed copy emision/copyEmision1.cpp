#include <iostream>

struct Foo {
  Foo() { std::cout<<"Constructed"<<std::endl; }
  Foo(const Foo &) = delete;
  Foo(const Foo &&) = delete;
  ~Foo() { std::cout<<"Destructed"<<std::endl; }
};

Foo f() {
  return Foo();
} 

int main() {
  Foo foo = f();
}
