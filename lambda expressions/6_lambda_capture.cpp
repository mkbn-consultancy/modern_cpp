//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include<iostream>
#include<vector>
#include<algorithm>

//COUNT HOW MANY NUMBERS IN RANGE DIVIDED BY X

//C++98 syle:
//we need to declare a functor and send it to std::count_if

struct isMultOf{
    isMultOf(int m) : _mult{m}{}
    bool operator()(int x){
        return !(x%_mult);
    }
private:
    int _mult;
};

void test98(){
    std::vector<int> vec{ 1,2,3,4,5,6,7,8 };
    int mult = 3;
    size_t s = std::count_if(vec.begin(), vec.end(), isMultOf(mult));
    std::cout<< "# of mult of "<<mult<<" is: "<<s<<"\n";
}

//C++11 style:
//we don't need the whole struct. we need to declare a lambda 
//and sent to it the mult value

void test11(){
   std::vector<int> vec{ 1,2,3,4,5,6,7,8 };
    int mult = 3;
    size_t s = std::count_if(vec.begin(), vec.end(), 
            [&](int x){return !(x%mult);});
    std::cout<< "# of mult of "<<mult<<" is: "<<s<<"\n";
}

int main(){
    test98();
    test11();
}