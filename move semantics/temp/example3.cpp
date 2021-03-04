#include <iostream>

class CClassC {
public:
	CClassC() = default;
	CClassC(const CClassC& cobj) { std::cout << "copy ctor\t"; }
	CClassC(CClassC&& cobj) { std::cout << "move ctor\t"; }
};

CClassC get(CClassC c) {
	return c;
}

void foo(CClassC& cobj) {
	std::cout << "in foo with l-value\n";
}
/*
void foo(CClassC&& cobj) {
	std::cout << "in foo with r-value\n";
}
*/
int main() {
	CClassC cobj;
	foo(cobj);
	foo(get(cobj));

	return 0;
}