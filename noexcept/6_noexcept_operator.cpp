#include <iostream>

void a() {

}

void b() noexcept{
    a();
}

int main(){
    std::cout<<std::boolalpha<<noexcept(a())<<std::endl;    //true
    std::cout<<std::boolalpha<<noexcept(b())<<std::endl;    //false
}