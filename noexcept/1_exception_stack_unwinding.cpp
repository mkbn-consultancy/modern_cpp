#include <iostream>
#include <limits>
#include <stdexcept>
#include <memory>

struct MyClass
{
    MyClass() {std::cout<<"inside default ctor...\n";}
    ~MyClass() {std::cout<<"inside dtor...\n";}
};

void test(int x, int y)
{
    // MyClass* p1 = new MyClass;
    std::shared_ptr<MyClass> p1(new MyClass);
    
    if(y==0){
        throw std::runtime_error("cannot divide by zero!\n");
    }
    std::cout<<"result is: "<<x/y<<std::endl;
}

int main(){
    try{
        test(3,0);
    }
    catch(std::runtime_error& err){
        std::cout<<"in main: Exception: "<<err.what()<<std::endl;
    }
    catch(...){
        std::cout<<"in main: Unknown Exception Caught!\n";
    }
}