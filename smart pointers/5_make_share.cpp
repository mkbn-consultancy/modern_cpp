#include <iostream>
#include <memory>

int seed() {return 0;}

void foo(std::shared_ptr<int> p, int init){
    *p = init;
}

int main(){
    foo(std::shared_ptr<int>(new int(42)), seed());

    foo(std::make_shared<int>(42),seed());

    //--------------------------------------------
    
    int* pn = new int(10);
    std::shared_ptr<int> spn(pn);

    (*pn)++;
    std::cout<<"pn="<<*pn<<", spn="<<*spn<<std::endl;
    std::cout<<spn.use_count()<<std::endl;

    delete pn;
    std::cout<<spn.use_count()<<std::endl;  //still 1!
    std::cout<<*spn;    //undefined behavior!
}