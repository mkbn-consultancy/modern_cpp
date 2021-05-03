//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <tuple>

void test1()
{
	std::tuple<int,char,float> data(20,'g',17.5);

	std::cout<<"the size of the tuple is: "<< 	std::tuple_size<decltype(data)>::value <<std::endl;
}

void test2()
{
	int i;
	char c;
	float f;

	std::tuple<int,char,float> tup1(20,'g',17.5);

	std::tie(i,std::ignore,f) = tup1;

	std::cout<<"Values of tuple are: "<<i<<","<<c<<","<<f<<std::endl;
}

void test3() 
{ 
	std::tuple <char, int, float> data; //all values are zero

	data = std::make_tuple('a', 10, 15.5); //init the tuple

	std::cout << "The initial values of tuple are : "; 
	std::cout << std::get<0>(data) << " " << std::get<1>(data); 
	std::cout << " " << std::get<2>(data) << std::endl; 

	std::get<0>(data) = 'b'; 
	std::get<2>(data) = 20.5; 

	std::cout << "The modified values of tuple are : "; 
	std::cout << std::get<0>(data) << " " << std::get<1>(data); 
	std::cout << " " << std::get<2>(data) << std::endl; 
} 

void test4(){ 
	std::tuple <int,char,float> tup1(20,'g',17.5); 
	std::tuple <int,char,float> tup2(30,'f',10.5); 
	
	auto tup3 = std::tuple_cat(tup1,tup2); //size of tup3 is 6!

	std::cout<<"The size of the new tuple is: ";
	std::cout<< std::tuple_size<decltype(tup3)>::value <<std::endl;
}


int main(){

}

