#include <initializer_list>
#include <iostream>

struct Foo {
	Foo() {}

	Foo(std::initializer_list<Foo>) {
		std::cout << "initializer list" << std::endl;
	}

	Foo(const Foo&) {
		std::cout << "copy ctor" << std::endl;
	}
};

int main() {
	Foo a;
	Foo b(a); // copy ctor
	Foo c{a}; // copy ctor (init. list element) + initializer list!!!
}