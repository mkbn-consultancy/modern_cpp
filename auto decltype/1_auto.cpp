#include <iostream>

template <class T1, class T2>
T1 add(const T1& a, const T2& b){
    return a+b;
}

void func(){
    static auto a = 5;
    a++;
    std::cout<<a<<std::endl;
}

int main(){
    std::cout<<add(1,2.8)<<std::endl;
    std::cout<<add(1.8,2)<<std::endl;

    //-------------------------

    auto i = 4;
    auto l = 42LL;
    auto p = new double; 

    func();
    func();
}