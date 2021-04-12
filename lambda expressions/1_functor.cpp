//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::set<int,

bool isOdd(int x){
	return x%2==1;
}

struct isOddF{
	bool operator()(int x){ return x%2==1; }
};

void test(){
	isOddF f;	
	f.operator()(3);
	f(3); //functor / function object
}

//////////////////////////////////////////////


struct isEvenF{
	bool operator()(int x){ return x%2==0; }
};

struct isPosF{
	bool operator()(int x){ return x>0; }
};

struct isNegF{
	bool operator()(int x){ return x<0; }
};

int main(){
	std::vector<int> vec{1,2,3,4,5,6,7,8};

	//option 1: pointer to function
	size_t s = std::count_if(vec.begin(), vec.end(),  isOdd);
	std::cout << "# of odd integers: " << s << "\n";

	//option 2: function object
	s = std::count_if(vec.begin(), vec.end(),  isOddF());
	std::cout << "# of odd integers: " << s << "\n";
}