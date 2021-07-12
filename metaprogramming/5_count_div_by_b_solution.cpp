//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>


template <bool T>
struct if_div_
{
    enum{result = T};
};

// template <>
// struct if_div_<true>
// {
//     enum{result=1};
// };

// template <>
// struct if_div_<false>
// {
//     enum{result=0};
// };

//---------

template <unsigned int n, unsigned int b>
struct count_div_by_b_numbers_till_a{
    enum { value = if_div_<(n%b==0)>::result + count_div_by_b_numbers_till_a<n-1,b>::value };
};

template <unsigned int b>
struct count_div_by_b_numbers_till_a<1,b>{
    enum { value = 0 };
};

template <>
struct count_div_by_b_numbers_till_a<1,1>{
    enum { value = 1 };
};

//---------

int main()
{
    std::cout<<"#numbers till 20 divided by 3 is: "<<
        count_div_by_b_numbers_till_a<20,3>::value <<
        std::endl;
}
