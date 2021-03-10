#include <iostream>

template<typename T>              // (2)
struct removeConst{ 
    typedef T type;               // (5)
};

template<typename T>              // (4)
struct removeConst<const T> { 
    typedef T type;               // (5)
};


int main(){
    
    std::cout<<std::boolalpha<<std::is_same<int, removeConst<int>::type>::value<<std::endl;        // true (1)
    std::cout<<std::boolalpha<<std::is_same<int, removeConst<const int>::type>::value<<std::endl;  // true (3)
  
}