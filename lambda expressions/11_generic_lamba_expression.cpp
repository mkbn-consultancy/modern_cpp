#include <iostream>
#include <string>

//C++11
template<typename T>
void func(T t){
    //declaring a lambda whos parameter is of type T
    auto fn = [](decltype(t) t){ return t;};
    //invoke the lambda with parameter t
    std::cout << fn(t) << std::endl;
}
void test11(){
    std::string s("My string");
    func(s);
    func(1024);
    func(true);
}

//C++14:

void test14(){
    auto fn2 = [](auto t) { std::cout<<t<<std::endl;};

    std::string s("My string");
    fn2(s);
    fn2(1024);
    fn2(true);

    std::cout<<"-------------------\n";
    auto max = [](auto a, auto b) {return a>b?a:b;};
    
    std::cout<< max(1,2) <<std::endl;
    std::cout<< max(1.5,2) <<std::endl;
    std::cout<< max(1,2.8) <<std::endl;
}

int main() {
    test11();
    std::cout<<"-------------------\n";
    test14();
}