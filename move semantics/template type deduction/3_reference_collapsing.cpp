#include <iostream>

class CMyClassA {
public:
	CMyClassA() = default;
	CMyClassA(const CMyClassA& cobj) { std::cout << "copy ctor\n"; }
//	CMyClassA(CMyClassA&& cobj) { std::cout << "move ctor\n"; }
};

void funcByValue(CMyClassA obj) {
//	std::cout << "funcByValue\n";
}

void funcByRef(CMyClassA& obj) {
//	std::cout << "funcByRef\n";
}
/*
void funcByRefRef(CMyClassA&& obj) {
//	std::cout << "funcByRefRef\n";
}
*/
template<class T>
void funcTempByRefRef(T&& obj) {

}

CMyClassA get(CMyClassA a) {
	std::cout << "creating obj\n";
	return a;
}

void check() {
	CMyClassA obj; //lvalue object.

	std::cout << "send to funcByValue:\n";
	funcByValue(obj);	//expect to call copy ctor
	funcByValue(get(obj));	//expect to call move ctor
	std::cout << "\n--------------\n";

	std::cout << "send to funcByRef:\n";
	funcByRef(obj);	//expect to not call any ctor
	funcByRef(get(obj));	//expect to call move ctor
	std::cout << "\n--------------\n";

	std::cout << "send to funcByRefRef:\n";
//	funcByRefRef(obj);	//compilation error: cannot bind l-value to r-value reference
//	funcByRefRef(createObj());	//expect to call move ctor
	std::cout << "\n--------------\n";

	std::cout << "send to funcTempByRefRef:\n";
	funcTempByRefRef(obj);	//l-value is deduced to be T& -> no ctor is called
	funcTempByRefRef(get(obj));	//r-value is deduced to T&& -> move ctor
	std::cout << "\n--------------\n";

}