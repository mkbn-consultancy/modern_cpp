#include<iostream>
#include<vector>
#include<algorithm>

//SUM ALL POSITIVE NUMBERS IN RANGE

int main()
{
    std::vector<int> vec{ 1,2,3,4,5,6,7,8 };
    int sum = 0;
    
    //C++98 style
    std::for_each(vec.begin(), vec.end(), ??? );


    //C++11 style
    std::for_each(vec.begin(), vec.end(), ??? );
    std::cout<< "sum of pos numbers is: "<<sum<<"\n";
}
