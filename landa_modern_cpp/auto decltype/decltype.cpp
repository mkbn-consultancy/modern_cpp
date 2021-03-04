////////////////////////////////////////////////////////
#include <iostream>
#include <iterator> //THIS INCLUDE WAS MISSING!!! :(
////////////////////////////////////////////////////////

template <auto N>
class Vector{
    int arr[N];
};

//the type of the argument T is depended on other template class - template<size_t>
//this is called template-template-parameter
template <template<auto> class T, auto K>
void func(const T<K>&){
    std::cout<<"K = "<<K<<std::endl;
}

int main(){
    Vector<3> f;
    func(f);
    Vector<'A'> f2;
    func(f2);
}
