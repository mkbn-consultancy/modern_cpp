//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

template<typename T>
void print(std::initializer_list<T> args){
    for(const auto &x : args){
        std::cout<< x <<" ";
    }
    std::cout<<std::endl;
}


///////////////////////////////////////////////


void print2(){
    std::cout<<std::endl;
}

template<typename T, typename... Params>
void print2(T a, Params...args){
    // std::cout<<sizeof...(args)<<std::endl;
    std::cout<<a;
    if(sizeof...(args)!=0){
        std::cout<<", ";
    }
    print2(args...);
}

void print3(){
    std::cout<<std::endl;
}

template<typename T, typename... Params>
void print3(const T& a, const Params&...args){
    // std::cout<<sizeof...(args)<<std::endl;
    std::cout<<a;
    if(sizeof...(args)!=0){
        std::cout<<", ";
    }
    print3(args...);
}

template<typename T, typename... Params>
void print4(T&& a, Params&&...args){
    // std::cout<<sizeof...(args)<<std::endl;
    std::cout<<a;
    if(sizeof...(args)!=0){
        std::cout<<", ";
    }
    print4(std::forward<Params>(args)...);
}

int main(){
    // print<int>({1,2,3,4,5.5});   //ERROR! 
    print2(1,2,3,4,5.5); 
}

