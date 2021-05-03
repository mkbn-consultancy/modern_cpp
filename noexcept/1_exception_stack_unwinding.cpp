//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <limits>
#include <stdexcept>
#include <memory>

struct MyClass
{
    MyClass() {std::cout<<"[MyClass:] inside default ctor...\n";}
    ~MyClass() {std::cout<<"[MyClass:] inside dtor...\n";}
};

void test(int x, int y)
{
    // MyClass* p1 = new MyClass;
    std::cout<<"[test:] creating a new local shared_ptr<MyClass> object\n";
    std::shared_ptr<MyClass> p1(new MyClass);
    
    if(y==0){
        std::cout<<"[test:] throwing an exception -> stack unwinding starts...\n";
        throw std::runtime_error("[test] cannot divide by zero!\n");
    }
    std::cout<<"[test:] result is: "<<x/y<<std::endl;
}

void deliverException(int x, int y)
{
    std::cout<<"[deliverException:] creating a new local shared_ptr<MyClass> object\n";
    std::shared_ptr<MyClass> p1(new MyClass);
    test(x,y);
    std::cout<<"[deliverException:] function ended successfully\n";
}

int main(){
    try{ 
        deliverException(3,0);
    }
    catch(std::runtime_error& err){
        std::cout<<"[main:] Caught Exception: "<<err.what()<<std::endl;
    }
    catch(...){
        std::cout<<"[main:] Unknown Exception Caught!\n";
    }
}