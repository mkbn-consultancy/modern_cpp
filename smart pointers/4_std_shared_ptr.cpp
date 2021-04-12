#include <iostream>
#include <memory>

void foo(int* p){
}

void bar(std::shared_ptr<int> p){
    ++(*p);
    std::cout<<p.use_count()<<std::endl;
}

int main(){
    std::shared_ptr<int> p1(new int(42));
    std::cout<<p1.use_count()<<std::endl; //print the reference counter

    std::shared_ptr<int> p2 = p1;

    //same as sending new int(42)
    auto p3 = std::make_shared<int>(42);
    std::cout<<"p3 ref. count = "<<p3.use_count()<<std::endl;

    bar(p1);
    foo(p2.get());

    std::cout<<p2.use_count()<<std::endl;
}