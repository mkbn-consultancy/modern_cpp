//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

template<typename T> 
void f(T x, T y) { 
	std::cout << "Template" << std::endl;
}

void f(int w, int z) { 
	std::cout << "Non-template" << std::endl;
}

int main()
{
   f( 1 ,  2 );
   f('a', 'b');
   f( 1 , 'b');
}
