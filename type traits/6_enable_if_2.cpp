#include <iostream>
#include <type_traits>
#include <limits>

//example from : https://stackoverflow.com/questions/25251380/stdnumeric-limits-as-a-condition

template<typename T>
void isInt(T t){}
template<typename T>
void isFloat(T t){}
template<typename T>
void isString(T t){}

template < typename T >
void foo( const T& param )
{
    if( std::numeric_limits< T >::is_integer)
    {
        isInt( param );
    }
    else if( std::numeric_limits< T >::is_specialized )
    {
        isFloat( param );
    }
    else
    {
        isString( param );
    }
}

//the more elegant way using enable_if to make the compiler choose the right
//function instead of paying at runtime on the branch:
template<typename T, 
         typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
void bar(const T& param) {
    isInt(param);
}

template<typename T, 
         typename std::enable_if<std::is_floating_point<T>::value, int>::type = 0>
void bar(const T& param) {
    isFloat(param);
}

template<typename T, 
         typename std::enable_if<!std::is_integral<T>::value && 
                                 !std::is_floating_point<T>::value, int>::type = 0>
void bar(const T& param) {
    isString(param);
}

int main(){
    int x = 5;
    foo(x);
    bar(x);
}

