//source: https://programming.vip/docs/c-std-function-example.html

#include <functional>
#include <iostream>

struct Foo {
    Foo(int num) : _num(num) {}
    void print_add(int i) const { std::cout << _num+i << '\n'; }
    int _num = 1;
};

//regular function
void print_num(int i)
{
    std::cout << i << '\n';
}
//function object
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

int main()
{
    // Store free function
    std::cout << "---Store free function\n";
    std::function<void(int)> f_display = print_num;
    f_display(-9);

    // Storage lambda
    std::cout << "---Store lambda\n";
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();
    std::function<void(int)> f_display_lambda = [](int i) { std::cout<<i<<std::endl; };
    f_display_lambda(10);

    // Results stored in the std::bind call
    std::cout << "---Store to std::bind Result of call\n";
    // Parameter passed in when bind
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();

    // Calls stored in member functions
    std::cout << "\n Calls stored in member functions\n";
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(2000);
    f_add_display(foo, 1);
    f_add_display(1000, 1); // A foo object is constructed by default?

    // Calls stored in data member accessors
    std::cout << "\n Calls stored in data member accessors\n";
    std::function<int(Foo const&)> f_num = &Foo::_num;
    std::cout << "Foo::_num: " << f_num(foo) << '\n';

    // Calls stored in member functions and objects
    std::cout << "\n Calls stored in member functions and objects\n";
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo, _1 );
    f_add_display2(2);

    // Calls stored to member functions and object pointers
    std::cout << "\n Calls stored to member functions and object pointers\n";
    std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3);

    // Calls stored in function objects
    std::cout << "\n Calls stored in function objects\n";
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);

    return 0;
}

