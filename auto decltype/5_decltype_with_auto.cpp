//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

/*
template <typename T1, typename T2>
T2 add(const T1& a, const T2& b){
	return a+b;
}
*/

//C++14
template <typename T1, typename T2>
decltype(auto) add1(const T1& a, const T2& b){
	return a+b;
}
//Can also be written like this:
template <typename T1, typename T2>
auto add2(const T1& a, const T2& b){
	return a+b;
}

//But consider the following example:

//plain auto never deduces to a reference
template < typename T > 
auto foo( T& t ) { 
    return t.value() ; 
}

//auto& always deduces to a reference
template < typename T > 
auto& bar( T& t ) { 
    return t.value() ; 
}

// return prvalue if t.value() is an rvalue
// return lvalue if t.value is an lvalue
// decltype(auto) has decltype semantics (without having to repeat the expression).
template < typename T > 
decltype(auto) foobar( T& t ) { 
    return t.value() ; 
}

void testAutoDecltype()
{
   struct A { int i = 0 ; int& value() { return i ; } } a;
   struct B { int i = 0 ; int value() { return i ; } } b;

//    foo(a) = 20;
        //Error: a.value() returns int& but foo(a) returns r-value.
   
   //Fine: b.value() returns int and foo(b) is also int.
   foo(b);

   //Fine: a.value() returns int& and bar's return value is auto& this int& (lvalue).
   bar(a) = 20;
   
//    bar(b) ; // *** error: auto& always deduces to a reference
        //Error: b.value() returns int and bar's return value is int&, 
        //       but we cannot return reference to local variable

   //the return value of foobar is always as the return type of t.value()
   foobar(a) = 20 ; // Fine: expression evaluates to lvalue of type int
   foobar(b) ;      // Fine: expression evaluates to prvalue of type int
}

int main(){
	std::cout<< add1(1.8 , 2) << std::endl;
	std::cout<< add2(2 , 1.8) << std::endl;

    testAutoDecltype();
}
