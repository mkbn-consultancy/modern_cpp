#include <iostream>

class CMyClass {
public:
	CMyClass() = default;
	CMyClass(const CMyClass& cobj) { std::cout << "copy ctor\t"; }
	CMyClass(CMyClass&& cobj) { std::cout << "move ctor\t"; }
};

CMyClass get(CMyClass m) {
	return m;
}

void foo(CMyClass cobj) {
	std::cout << "in foo\n";
}

template <class T>
void relayRV(T&& cobj) {
	std::cout << "in relay\t";
	foo(std::forward<T>(cobj)); //send by value
}

int main() {
	CMyClass cobj;
	std::cout << "--------------\n";

	//pass a l-value object
	relayRV(cobj);	//l-value is passed as T&
	std::cout << "--------------\n";

	//pass a r-value object
	relayRV(get(cobj)); //r-value is passed with move ctor
	std::cout << "--------------\n";

	return 0;
}

