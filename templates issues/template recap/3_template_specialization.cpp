//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
//A template can be specialized for particular template arguments.
#include <iostream>

struct Foo{
    int impl_ptr;
};

template <typename T>
void swap(T &v1, T &v2) 
{
    std::cout<<"inside swap(T&,T&)\n"; 
	T t = v1; v1 = v2; v2 = t; 
}

template <>
void swap<Foo>(Foo &f1, Foo &f2) 
{
    std::cout<<"inside swap(Foo&,Foo&)\n";
    swap(f1.impl_ptr, f2.impl_ptr); 
}

int main()
{
    Foo foo1,foo2;
    swap(foo1,foo2);
}
