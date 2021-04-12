//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <utility>

class A {
private:
	int*	_arr;
	size_t	_size;
	size_t	_capacity;
public:
	A() : _arr(nullptr), _size(0), _capacity(0) {}
	A(size_t size) : _size(size), _capacity(0), _arr(new int[size]) {}
	A(const A& a) {
		_arr = new int[a._size];
		int i;
		for (i = 0; i < a._size; ++i) {
			_arr[i] = a._arr[i];
		}
	}
	A(A&& a) : _arr(a._arr), _size(a._size), _capacity(a._capacity){
		a._arr = nullptr;
		a._size = 0;
		a._capacity = 0;
	}

	~A() { delete _arr; }
};

class B {
private:
	A _aObj;
public:
	B(size_t size) : _aObj(size) {}

	B(const B& b) : _aObj(b._aObj) {}
	B(B&& b) : _aObj(std::move(b._aObj)) {}
};

int mainMoveSemantic1()
{
	B bObj1(5);

	B bObj2(bObj1);

	return 0;
}

int main()
{
	
}

