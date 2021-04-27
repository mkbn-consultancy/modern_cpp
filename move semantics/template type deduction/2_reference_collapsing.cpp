//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

typedef int&  lref;
typedef int&& rref;

int n;
lref&  r1 = n; // type of r1 is int&

lref&& r2 = n; // type of r2 is int&: A& && becomes A&

rref&  r3 = n; // type of r3 is int&: A&& & becomes A&

rref&& r4 = 1; // type of r4 is int&&: A&& && becomes A&&

void testTypes()
{

}
//---------------------------------------------------------

//Case 1: Passing param by reference/pointer

template  <class T>
void f(T& param){}

void testCase1_1(){
    int x=22;
    f(x);   //int --> T&
            //T is int / param is int&

    const int cx = x;
    f(cx);  //const int --> T&
            //T is const int / param is const int&

    const int& crx = x;
    f(crx); // const int& --> T&
            // T is const int / param is const int&
}

//---------

template <class T>
void f(T* param){}

void testCase1_2(){
    int x=22;
    const int* cx = &x;

    f(&x);  //int --> T*
            //T is int / param is int*

    f(cx);  //T is const int / param is const int*

    //Notice: T is not a pointer!!
}

//---------

template <class T>
void f(const T& param){}

void testCase1_3(){
    int x=22;
    f(x);   //int --> const T&
            //T is int / param is const int&

    const int cx = x;
    f(cx);  //const int --> const int& T
            //T is const int / param is const int&

    const int& crx = x;
    f(crx); // const int& --> const T&
            // T is const int / param is const int&
}

void testCase1_4(){
    //sending parameter is the same rule as auto:
    //the auto is equivalent to T

    int x = 22;
    auto& v1 = x;   // int --> auto& v1 
                    // (int --> T& param ==> T is int param is int&)
                    // auto = int / v1 is auto&

    const int cx = x;
    auto& v2 = cx;  // const int --> auto&
                    // (T is const int / param is const int&)
                    // auto is const int / v2 is const int&

    const int& crx = x;
    auto& v3 = crx; // const int& --> auto&
                    // (T is const int / param is const int&)
                    // auto is const int / v3 is const int&

    const auto& v4 = x; // int --> const auto&
                        // (T is const int / param is const int&)
                        // auto is const int / v4 is const int&

    const auto& v5 = cx;    // const int --> const auto&
                            // (T is int / param is const int&)
                            // auto is const int / v5 is const int&

    const auto& v6 = crx;   // const int& --> const auto&
                            // (T is const int / param is const int&)
                            // auto is const int / v6 is const int&
}

//---------------------------------------------------------

//Case 2: Universal Reference

//In templates (ONLY!!), T&& can catch both l-value and r-value

template <class T>
void f(T&& param){}

void testCase2_1()
{
    //all those variables are l-values!
    //sendint l-value to f(T&&) makes T to be deduced as T& !
    int x = 22;
    const int cx = x;
    const int& crx = x;

    f(x);   // int --> T&&  :   T&& becomes T&
            // T = int& / param = int&

    f(cx);  // const int --> T&&
            // T = const int& / param = const int&

    f(crx); // const int& --> T&&
            // T = const int& / param = const int&

    f(22);  // sending r-value!
            // T = int / param = int&&
}

int main()
{
        testTypes();
}