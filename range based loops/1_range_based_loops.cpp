//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <map>

int main()
{
    //old style for loop
    std::map<int,std::string> names = {{1,"avi"}, {2,"gil"}, {3, "shira"}};
    for(auto itr = names.begin(); itr != names.end(); ++itr){
        std::cout<<itr->second<<" ";
    }
    std::cout<<std::endl;

    //C++11 style:
    for(auto i : names){
        std::cout<<i.second<<" "; //i is std::pair<int,std::string>
    }
    std::cout<<std::endl;

    //iterate over std::initializer_list:
    for(auto i : {1,2,3,4}){
        std::cout<< i*i << " ";
    }
    std::cout<<std::endl;
}
