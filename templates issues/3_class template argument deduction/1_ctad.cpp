//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <vector>
#include <mutex>
#include <tuple>

//until c++17 the compiler cannot deduce the int
//out of the initializer list.
std::vector<int> v{1,2,3,4};

//since C++17:
std::vector v2{1,2,3,4};
std::tuple p{1,2};
std::mutex m;
std::lock_guard lk{m}; //no need to write std::lock_guard<std::mutex>

template<typename T>
class MyClass
{
public:
    MyClass(const T&){}
};

MyClass m1{5};  //instead of MyClass<int> m1{5};
auto pm = new MyClass{4.5};    //instead of new Data<double>{4.5};

int main()
{}