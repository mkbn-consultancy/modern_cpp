//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
   #include <iostream>
#include <map>
#include <vector>
#include <string>

int main()
{
    std::map<std::string,std::vector<std::string>> foodNames =
    {
        {"drinks",{"water", "milk", "juice"}},
        {"fruits",{"apple", "grapes"}},
        {"vegetables",{"carrot", "potato", "cucumber"}}
    };

    //use range-based for loop to print all data to screen:
    // drinks: water milk juice 
    // fruits: apple grapes
    // vegetables: carrot potato cucumber
 
    for(auto i : foodNames){
        std::cout<<i.first<<": ";
        for(auto j : i.second){
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}