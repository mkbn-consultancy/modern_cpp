#include <iostream>
#include <vector>

// template<class T>
// void print_container_elements(T& data){
//     for(auto itr = data.begin(); itr != data.end(); ++itr){
//         std::cout<<*itr<<" ";
//     }
//     std::cout<<std::endl;
// }

template<class T>
void print_container_elements(T& data){
    std::cout<<sizeof(T)<<std::endl;

    for(auto itr = std::begin(data); itr != std::end(data); ++itr){
        std::cout<<*itr<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    std::vector<int> vi { 1,2,3 };

    //printing all elements:
    // print_container_elements(vi);

    int arr[] = { 1,2,3 };
    print_container_elements(arr);
}