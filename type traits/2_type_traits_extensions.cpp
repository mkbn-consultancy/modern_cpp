#include <type_traits>
#include <iostream>

void cpp11_traits(){
    
    std::is_same<int, std::remove_const<int>::type>::value;        // true
    std::is_same<int, std::remove_const<const int>::type>::value;  // true
  
}

void cpp14_traits(){
    
    std::is_same<int, std::remove_const_t<int>>::value;        // true
    std::is_same<int, std::remove_const_t<const int>>::value;  // true
  
}

void cpp17_traits(){
    
    std::cout<<std::boolalpha<<std::is_same_v<int, std::remove_const_t<int>>;        // true
    std::cout<<std::boolalpha<<std::is_same_v<int, std::remove_const_t<const int>>;  // true
  
}

int main()
{
    cpp17_traits();
}

