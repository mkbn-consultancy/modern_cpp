#include <iostream>
#include <vector>

using comp = bool(*)(int,int);

void sort(std::vector<int>& vec, comp fn)
{
    std::cout<<"inside sort...\n";
    for(size_t i=0; i<vec.size()-1; ++i){
        for(size_t j=0; j<vec.size()-i-1; ++j){
            if(fn(vec[j],vec[j+1])){
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}

bool biggerThen(int a, int b){
    return a>b;
}

int main()
{
    std::vector<int> vec = {5,8,1,9,4,2,8};
 
    for(auto i : vec){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
 
    //sort(vec,biggerThen);
    sort(vec,[](int a, int b){ return a>b;});   //although sort gets a function ptr

    for(auto i : vec){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}