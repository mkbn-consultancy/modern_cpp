//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

template< class T > 
struct is_pointer{ 
  static const bool value = false; 
};

template< class T > 
struct is_pointer< T* >{ 
  static const bool value = true; 
};

template<class T>
bool is_pointer_check(T x){
    return is_pointer<T>::value;
}

int* testFunc(){
    static int x;
    return &x;
}

int main()
{
    int x;
    int* p = &x;
    const int* pc = &x;

    std::cout<<"is x a pointer? "<<is_pointer_check(x)<<std::endl;
    std::cout<<"is p a pointer? "<<is_pointer_check(p)<<std::endl;
    std::cout<<"is pc a pointer? "<<is_pointer_check(pc)<<std::endl;
    std::cout<<"is testFunc a pointer? "<<is_pointer_check(testFunc())<<std::endl;
    std::cout<<"is string a pointer? "<<is_pointer_check("hello")<<std::endl;
}