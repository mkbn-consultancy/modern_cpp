#include <iostream>
#include <iterator>

template <size_t N>
class Foo{
    int arr[N];
};

//the type of the argument T is depended on other template class - template<size_t>
//this is called template-template-parameter
template <template<size_t> class T, size_t K>
auto getSize1(const T<K>&){
    return K;
}

//but here we know that we use size_t.
//what if we do not know this type?
template<typename InnerType, template<InnerType> class T, InnerType K>
auto getSize2(const T<K>&){
    return K;
}

//this works only in C++17.

//in C++17 we can simply write:
template <auto N>
class Bar{
public:
    int& operator[](int index){
        return arr[index];
    }
    int operator[](int index) const{
        return arr[index];
    }
private:
    int arr[N];
};

template <template<auto> class T, auto K>
auto getSize3(const T<K>&){
    return K;
}

template <template<auto> class T, auto K>
void print(const T<K>& arr){
    for(int i=0; i<getSize3(arr); i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::cout<< getSize1(Foo<8>()) << std::endl;
    std::cout<< getSize2(Foo<10>()) << std::endl;
    std::cout<< getSize3(Foo<'A'>()) << std::endl;

    Bar<5> b;
    for(int i=0; i<5; i++){
        b[i] = i;
    }

    print(b);
}