//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

struct A {double x;};

int main()
{
    A aObj;

    A* a = &aObj;

    decltype(a->x) y;   //y is double (declared type)
    y = 3.4;

    decltype((a->x)) z = y; //z is double& (lvalue expression)

    std::cout<<"y = "<<y<<" , z = "<<z<<std::endl; 

    z += 1.5;

    std::cout<<"y = "<<y<<" , z = "<<z<<std::endl; 

    //------- declare a const pointer -------
    const A* ca = &aObj;

    decltype(ca->x) r;  //double

    decltype((ca->x)) s = r; //const double& 

    //s += 1.5;   //error since s is const!
}