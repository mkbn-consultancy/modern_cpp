#include<iostream> 
#include<iomanip>   //for std::setprecision

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

int main() 
{ 
	double distance = 4.5_km; 
	std::cout << "(1) "<< distance << std::endl; 
	std::cout << "(2) "<< 3.9_mm << std::endl;  
	std::cout << "(3) "<< std::setprecision(8) << distance + 31.9_mm << std::endl; 
	std::cout << "(4) "<< 45.9_km / 2.0_m << std::endl; 
	std::cout << "(5) "<< 32.3_mm * 2.0_m << std::endl; 
	return 0; 
} 
