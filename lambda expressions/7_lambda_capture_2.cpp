#include <iostream>

struct A{
    A() { std::cout<<"inside A()\n"; }
    A(const A&) { std::cout<<"inside A(const A&)\n"; }
    void print() { std::cout << "printing A\n"; }
    void print() const { std::cout << "printing const A\n"; }
};

void example1(){
    int a, b;
    a = 1; b = 2;
    auto lambda_1 = [=] { std::cout << a << " " << b << std::endl; };
    auto lambda_2 = [&] { std::cout << a << " " << b << std::endl; };
    lambda_1(); // Prints: 1 2
    lambda_2(); // Prints: 1 2
    a = 4; b = 5;
    lambda_1(); // Prints: 1 2
    lambda_2(); // Prints: 4 5
}

void example2(){
    int a=4;
    auto increase_local_a = [a]() mutable {
        std::cout<< a << std::endl;
        a++;
    };

    auto decrease_ref_a = [&a]() {
        std::cout<< a << std::endl;
        a--;
    };

    increase_local_a();
    decrease_ref_a();
    increase_local_a();
    decrease_ref_a();
    increase_local_a();
    decrease_ref_a();

    std::cout<< a << std::endl;
}

int main()
{
    // A a, b;
    // std::cout<<"-----------\n";
    // auto fn1 = [=](){ a.print(); };
    // fn1(); 
    // std::cout<<"-----------\n";
    // auto fn2 = [&](){ a.print(); };
    // fn2();
    // std::cout<<"-----------\n";
    // // auto fn3 = [a](){ b.print(); }   //error. capturing only a and not b
    // //-----------------------
    // auto fn3 = [a](){ a.print(); }; //copy ctor is invoked
    // std::cout<<"-----------\n";

    // example1();
    std::cout<<"-----------\n";
    example2();
}