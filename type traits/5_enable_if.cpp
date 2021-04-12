//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <type_traits>

//turn the parameter to be its negative value

int 
negate(int i) { 
    std::cout<<"inside negate(int)\n";
    return -i; 
}

template <class T>
typename T::result_type 
negate(const T& f) { 
    std::cout<<"inside negate(T)\n";
    return -f(); 
}

void test1(){
    negate(1);  //the compiler instantiates an int version of the second negate function
                //resulting in int::result_type which is an error.
}

//instead we can add the following version:

template <class T>
T negate(T t, typename std::enable_if< std::is_arithmetic<T>::value >::type* dummy = 0){
    std::cout<<"inside negate(T, enable_if)\n";
    // ...
    return t;
}

struct B{
};

void test2(){
    B obj;
    // negate(obj); //error: no matching function since obj is not arithmetic
    negate(1);
    negate(1.5);    //the first is not exact match, the second is error, third is exact match
}

////////////////////////////////////

template <class T>
typename std::enable_if< std::is_arithmetic<T>::value, T >::type    //the return type is T
foo(T t)
{
    std::cout<<"inside enable_if<T> foo(T) \n";
    // ...
    return t;
}

void test3()
{
    foo(3);

    B obj;
    // foo(obj);
}

////////////////////////////////////
int main(){
    std::cout<<"\n";
    std::cout<<"test1............\n";
    test1();
    std::cout<<"test2............\n";
    test2();
    std::cout<<"\n";
    std::cout<<"test3............\n";
    test3();
    std::cout<<"\n";
}