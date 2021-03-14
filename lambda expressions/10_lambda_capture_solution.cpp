#include<iostream>
#include<vector>
#include<algorithm>

//SUM ALL POSITIVE NUMBERS IN RANGE

int main()
{
    std::vector<int> vec{ 1,2,3,4,5,6,7,8 };
    int sum = 0;
    std::for_each(vec.begin(), vec.end(), [&sum](int x){ if(x>0) sum+=x; } );
    std::cout<< "sum of pos numbers is: "<<sum<<"\n";
}
