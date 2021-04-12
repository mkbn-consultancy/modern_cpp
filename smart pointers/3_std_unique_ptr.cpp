#include <iostream>
#include <memory>

void foo(int* p){
    std::cout<< *p <<std::endl;
}

int main(){
    std::unique_ptr<int> p1(new int(42));
    // we do not have copy constructor for unique_ptr:
    // std::unique_ptr<int> p2 = p1;    //ERROR!
    
    std::unique_ptr<int> p2 = std::move(p1);    //call move ctor of unique_ptr
                                                //and transfer ownership

    //p1 is empty so we will not enter the if block
    if(p1){
        std::cout<<"sending p1 to foo...\n";
        foo(p1.get());
    }

    (*p2)++;

    if(p2){
        std::cout<<"sending p2 to foo...\n";
        foo(p2.get());
    }
}