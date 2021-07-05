//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <string.h>
#include <iostream>

template <class T> 
T MyMax(const T t1, const T t2) 
{
	std::cout<<"inside general MyMax...\n";
	return (t1 < t2) ? t2 : t1; 
} 

template<>
const char* MyMax<const char*>(const char* t1, const char* t2)
{
	std::cout<<"inside specific MyMax for const char*...\n";
	return strcmp(t1,t2)>0 ? t1 : t2;
}

int main() 
{ 
	int highest = MyMax(5,10); 
	char c = MyMax<char>('a', 'z'); 

	const char* str = MyMax("Aba","Ima");

	// vector<int> v = {1,2,3,4};
}
