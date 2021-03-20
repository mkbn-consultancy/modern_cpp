#include <iostream>

template<typename T>              
struct removeConst{ 
    typedef T type;               
};

template<typename T>              
struct removeConst<const T> { 
    typedef T type;               
};


int main(){
    
    std::cout<<std::boolalpha<<std::is_same<int, removeConst<int>::type>::value<<std::endl;        // true (1)
    std::cout<<std::boolalpha<<std::is_same<int, removeConst<const int>::type>::value<<std::endl;  // true (3)
  
}