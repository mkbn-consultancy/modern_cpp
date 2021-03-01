#include <iostream>

int x;
int& getRef()
{
    return x;
}
int getVal(){
    return x;
}

int main(){
    int i;

    int& r1 = i;    //OK. reference to l-value
//    int& r2 = 20;   //error: cannot declare a reference to rvalue
    const int& r3 = 20; //OK. const reference to rvalue

    int a;
    a = 1; //a is an lvalue

    getRef() = 4;   //lvalue is not a necessarity a variable
    std::cout<<"x = "<<x<<std::endl;

    getVal(); //the return value is rvalue
}