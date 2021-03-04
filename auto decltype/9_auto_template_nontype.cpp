
//compilation line:  g++ -std=c++17 .\auto_template_nontype_2.cpp

#include <iostream>
#include <iterator>

template <size_t N>
class Foo{
    int arr[N];
};

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


//the type of the argument T is depended on other template class - template<size_t>
//this is called template-template-parameter

template <template<auto> class T, auto K>
void print(const T<K>& arr){
    for(int i=0; i<K; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    Foo<3> f;
    Foo<'A'> f2;

    const int n = 5;
    //const char n = 'a';
    Bar<n> b;
    for(int i=0; i<n; i++){
        b[i] = i;
    }

    print(b);
}