//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

class CClassB {
public:
	CClassB() = default;
	CClassB(const CClassB& cobj) { std::cout << "copy ctor\t"; }
	CClassB(CClassB&& cobj) { std::cout << "move ctor\t"; }
};

CClassB get(CClassB b) {
	return b;
}

void foo(CClassB& cobj) {
	std::cout << "in foo with l-value\n";
}

void foo(CClassB&& cobj) {
	std::cout << "in foo with r-value\n";
}

int main() {
	CClassB cobj1;
	CClassB&& cobj = std::move(cobj1);
	foo(cobj);
	foo(get(cobj1));

	return 0;
}
