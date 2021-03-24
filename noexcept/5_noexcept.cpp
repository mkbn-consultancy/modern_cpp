#include <iostream>
#include <string>

void a() {
    throw std::string("from a");
}

void b(){
    a();
}

void c() noexcept {
    b();
}

int main()
{
    // c(); //will cause runtime error of std::terminate()

    std::cout<<std::boolalpha<<noexcept(c())<<std::endl;    //true
    std::cout<<std::boolalpha<<noexcept(b())<<std::endl;    //false
}