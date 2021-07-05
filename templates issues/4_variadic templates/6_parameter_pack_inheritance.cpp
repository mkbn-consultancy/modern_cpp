
//source: https://www.ibm.com/docs/en/zos/2.3.0?topic=only-variadic-templates-c11

#include <iostream>
using namespace std;

struct a1{};
struct a2{};
struct a3{};
struct a4{};

//base template class
template<class X> 
struct baseC{
    baseC() {printf("baseC primary ctor\n");}
};
//BaseC's specializations:
template<> 
struct baseC<a1>{
    baseC() {printf("baseC a1 ctor\n");}
};
template<> 
struct baseC<a2>{
    baseC() {printf("baseC a2 ctor\n");}
};
template<> 
struct baseC<a3>{
    baseC() {printf("baseC a3 ctor\n");}
};
template<> 
struct baseC<a4>{
    baseC() {printf("baseC a4 ctor\n");}
};

//inherit from all specializations:
template<class...A> 
struct container : public baseC<A>...{
    container(){
        printf("container ctor\n");
    }
};

int main(void){
    container<a1,a2,a3,a4> test;
    return 0;
}