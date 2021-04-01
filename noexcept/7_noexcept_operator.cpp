#include <iostream>
#include <string>

void a() {
    throw std::string("from a");
}

void b() throw(std::string){
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
    std::cout<<std::boolalpha<<noexcept(throw "hello")<<std::endl;    //false
}