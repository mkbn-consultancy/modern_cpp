#include <iostream>
#include <memory>

int main(){
    auto p1 = std::make_shared<int>(42);
    std::weak_ptr<int> wp = p1;

    std::cout<<"p1 ref. count = "<<p1.use_count()<<std::endl;

    {
        auto sharedP = wp.lock();   //a shared_ptr is created
        std::cout<<*sharedP<<std::endl;
        std::cout<<"p1 ref. count = "<<p1.use_count()<<std::endl;
    }

    std::cout<<"p1 ref. count = "<<p1.use_count()<<std::endl;

    p1.reset();

    if(wp.expired()){
        std::cout<< "expired" <<std::endl;
    }
}

