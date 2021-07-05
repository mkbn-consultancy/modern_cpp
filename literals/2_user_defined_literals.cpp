//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include<iostream> 
#include<iomanip>   //for std::setprecision

//suppose we want that meters will be the "official" unit
//thus we want to convert all other units to meters

//for compile-time calculations, declare the operators as constexpr
//https://godbolt.org/z/8cjY3x

// km
double operator"" _km( long double x ) { 
	return x*1000; 
} 

// m 
double operator"" _m( long double x ) { 
	return x; 
} 

// millimeter 
double operator"" _mm( long double x ){ 
	return x / 1000; 
} 

long double operator""_KG(long double x){	//OK. operator""  _KG is error.
	return x;
}

int main() 
{ 	
	double distance = 4.5_km; 
	std::cout << "(1) "<< distance << std::endl; 
	std::cout << "(2) "<< 3.9_mm << std::endl;  
	std::cout << "(3) "<< std::setprecision(8) << distance + 31.9_mm << std::endl; 
	std::cout << "(4) "<< 45.9_km / 2.0_m << std::endl; 
	std::cout << "(5) "<< 32.3_mm * 2.0_m << std::endl; 

	int a = 1'000;
	std::cout<<"a="<<a<<std::endl;

	return 0; 
} 

/*
long double operator "" _km(long double); // OK, will be called for 1.0_km
std::string operator "" _i18n(const char*, std::size_t); // OK
template <char...> double operator "" _π(); // OK
float operator ""_e(const char*); // OK
 
float operator ""Z(const char*); // error: suffix must begin with underscore
double operator"" _Z(long double); // error: all names that begin with underscore
                                   // followed by uppercase letter are reserved
double operator""_Z(long double); // OK: even though _Z is reserved ""_Z is allowed
*/

