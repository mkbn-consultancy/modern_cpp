#include <type_traits>
#include <iostream>

// template <typename T>
// T div(T a, T b){
//     //we wish to divide a and b only if they are floating point types
//     if(std::is_floating_point<T>::value==false){
//         std::cout<<"div::error::can be used only with floating point types\n";
//         return 0;
//     }
//     return a/b;
// }

template <typename T>
T mydiv(T a, T b){
    //we wish to divide a and b only if they are floating point types
    std::cout<<std::boolalpha<<std::is_floating_point<T>::value<<std::endl;
    static_assert(std::is_floating_point<T>::value, 
                    "div::error::can be used only with floating point types\n");
     return a/b;
}

int main(){
    std::cout<< mydiv(12.6,9.3) << std::endl;

    mydiv(2,4);
}