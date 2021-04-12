//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

int fun1() { return 10; }
char fun2() { return 'g'; }

int func1(int i) {return 5;}

template<class T1, class T2>
T1 add1(const T1& a, const T2& b){
	return a+b;	//always of type T1?
}

//C++11:
template<class T1, class T2>
auto add2(const T1& a, const T2& b) -> decltype(a+b){
	return a+b;	
}

//C++14:
template<class T1, class T2>
auto add3(const T1& a, const T2& b){
	return a+b;	
}

int main()
{
    int x;
    decltype(x) y;

	// Data type of x is same as return type of fun1()
	// and type of y is same as return type of fun2()
	// Np function call is made!!
	decltype(fun1()) a;
	decltype(fun2()) b;
	// decltype(func1(int)) c;

	//check the type of a and b
	std::cout << typeid(a).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;

    int w = 5;
    double z = 4.5;
    std::cout<< typeid(add1(w,z)).name() <<", result = "<<add1(w,z)<<std::endl;
    std::cout<< typeid(add2(w,z)).name() <<", result = "<<add2(w,z)<<std::endl;
    std::cout<< typeid(add3(w,z)).name() <<", result = "<<add3(w,z)<<std::endl;
    
    return 0;
}

