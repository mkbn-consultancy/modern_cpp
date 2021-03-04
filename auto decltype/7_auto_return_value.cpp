#include <iostream>

//C++03 style
struct Foo1{
	int val() const{
		return _m;
	}
	const int& cref() const{
		return _m;
	}
	int& mref(){
		return _m;
	}
private:
	int _m;
};

//C++14 style
struct Foo2{
	auto val() const{
		return _m;
	}
	auto& cref() const{
		return _m;
	}
	auto& mref(){
		return _m;
	}
private:
	int _m = 0;
};

int main()
{
	Foo2 f;
	auto& cref = f.cref();
	//cref++; //Error!
	auto& mref = f.mref();
	std::cout<<f.val()<<std::endl;
	mref++;
	std::cout<<f.val()<<std::endl;
}