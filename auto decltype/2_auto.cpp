//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <map>
#include <string>
#include <vector>

//---------------------------------------------------------------------------------
// Motivation for auto 1: we don't want to type so much code...
class Widget{};

std::map< std::string, std::vector< Widget > > table;

// C++98
std::map< std::string, std::vector< Widget > >::iterator i = table.find( "42" );

// Since C++11
auto j = table.find( "42" );

//---------------------------------------------------------------------------------
// Motivation for auto 2: sometimes we cannot know the type, only the compiler will know

// auto getLambda() -> decltype([](){std::cout<<"Hello World";}){ //compilation error!!
//     //lambda expression type is unpecified
//     return ([](){std::cout<<"Hello World";});
// }

//instead we can declare it like that:
auto getLambda(){
    //lambda expression type is unpecified
    return ([](){std::cout<<"Hello World";});
}

//---------------------------------------------------------------------------------
// auto as a return type

// function that returns a 'reference to int' type
int& fun() { static int x = 3; return x;  }

// m will default to int type instead of int& type
auto m = fun();

// n will be of int& type because of use of extra & with auto keyword
auto& n = fun();

template <typename Builder>
auto makeAndProcessObject (const Builder& builder) -> decltype( builder.makeObject() )
{
    auto val = builder.makeObject();
    // do stuff with val
    return val;
}
/*
template <typename A, typename B>
auto do_something(const A& a, const B& b)
{
  return a.do_something(b);
}
*/

//---------------------------------------------------------------------------------

int main()
{
    //------------------------------------------------------
    // compiler discards all qualifiers
    const int x = 2;
    auto var1 = x;   //var1 is "only" int, and not const int.
    var1++;
    const auto var2 = x;    //now var2 is a constant
    //var2++;   //ERROR!

    //------------------------------------------------------
    // auto& - compiler keeps the qualifiers
    auto& var3 = x; //var3 is a const reference 
    //var3++;   //ERROR!
    auto ptr = &x;  //ptr is a const int* 
    //(*ptr)++; //ERROR!

    //------------------------------------------------------
    auto f = getLambda();
    std::cout<<"Lambda output: ";
    f();
    std::cout<<std::endl;
}

