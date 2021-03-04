#include <iostream>

class CClassA {
public:
	CClassA() = default;
	CClassA(const CClassA& cobj) { std::cout << "copy ctor\t"; }
	CClassA(CClassA&& cobj) { std::cout << "move ctor\t"; }
};

CClassA get(CClassA a) {
	return a;
}

void foo(CClassA cobj) {
	std::cout << "in foo\n";
}

int main() {
	CClassA cobj;
	foo(cobj);
	foo(get());

	return 0;
}
