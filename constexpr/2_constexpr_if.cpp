//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <type_traits>

//C++17

template <typename T>
auto get_value(T t) {
    if constexpr (std::is_pointer_v<T>){
        return *t; // deduces return type to int for T = int*
    }
    else{
        return t;  // deduces return type to int for T = int
    }
}

template <typename T>
void printData(T& t){
    if constexpr (std::is_array_v<T>){
        std::cout<<sizeof(t)<<std::endl;
        for(auto x : t){
            std::cout<< x <<" ";
        }
        std::cout<<std::endl;
    }
    else if constexpr (std::is_pointer_v<T>){
        std::cout<<"pointer: "<< *t <<std::endl;
    }
    else{
        std::cout<<"integral: "<< t <<std::endl;
    }
}

int main(){
    int x = 5;
    int* pX = &x;

    std::cout<<get_value(x)<<std::endl;
    std::cout<<get_value(pX)<<std::endl;

    printData(pX);

    int arr[]{1,2,3,4,5};
    printData(arr);
}

//https://godbolt.org/z/3ean53