class Array {
private:
	int*	_arr;
	size_t	_size;
	size_t	_capacity;
public:
	Array() : _arr(nullptr), _size(0), _capacity(0) {}
	Array(size_t size) : _size(size), _capacity(0), _arr(new int[size]) {}
	
    Array(const Array& a) {
		_arr = new int[a._size];
		int i;
		for (i = 0; i < a._size; ++i) {
			_arr[i] = a._arr[i];
		}
	}

    Array(Array&& a){//move constructor 
        _arr = a._arr;
        _size = a._size;
        _capacity = a._capacity;

        a._arr = nullptr;
    }

    Array& operator=(Array&& a){
        
    }
};