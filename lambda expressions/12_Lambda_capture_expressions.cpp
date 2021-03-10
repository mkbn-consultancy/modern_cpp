#include <memory>
#include <iostream>

struct A{
    A() { std::cout<<"inside A()\n";}
    A(const A&) { std::cout<<"inside A(const A&)"; }
    ~A() { std::cout<<"inside ~A()\n"; }

    void print() { std::cout<<"inside print()\n"; }
};

int main()
{
    std::unique_ptr<A> ptr(new A);

    // auto fn = [ptr](){ ptr->print(); return *ptr; };    //Error! ptr has no copy constructor!

    auto fn = [p = std::move(ptr)](){ p->print(); return *p; };   //C++14
 
    fn();
}