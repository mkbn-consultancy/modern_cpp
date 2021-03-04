#include <iostream>

class B{
public:
    virtual void f(short) { std::cout<< "B::f" << std::endl; }
};

class D : public B{
public:
    virtual void f(int) override { std::cout<<" D::f" <<std::endl; }
        //compilation error! 'virtual void D::f(int)' marked 'override', but does not override
};

int main(){
    B* pB = new D;
    pB->f(5);
}