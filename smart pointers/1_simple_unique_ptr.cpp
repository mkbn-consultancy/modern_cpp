//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
//based on source: https://medium.com/swlh/c-smart-pointers-and-how-to-write-your-own-c0adcbdce04f

#include <iostream>

template <class T>
class my_unique_ptr
{
private:
	T * _ptr = nullptr;
public:
	my_unique_ptr() : _ptr(nullptr) {}
	my_unique_ptr(T * ptr) : _ptr(ptr) {}
	my_unique_ptr(const my_unique_ptr & obj) = delete; // copy constructor is deleted
	my_unique_ptr(my_unique_ptr && dyingObj) // move constructor
	{
		// Transfer ownership of the memory pointed by dyingObj to this object
		_ptr = dyingObj._ptr;
		dyingObj.ptr = nullptr; 
	}
	
	~my_unique_ptr() {
		cleanup();
	}

	my_unique_ptr& operator=(const my_unique_ptr & obj) = delete; // copy assignment is deleted
    void operator=(my_unique_ptr && dyingObj) // move assignment
	{
        if(this != &dyingObj){
            cleanup(); // cleanup any existing data

            // Transfer ownership of the memory pointed by dyingObj to this object
            _ptr = dyingObj._ptr;
            dyingObj.ptr = nullptr;
        }
	}
	T* operator->() { return _ptr; }
	T& operator*()  { return *(_ptr); }

private:
	void cleanup(){
		if (_ptr != nullptr)
			delete _ptr;
	}
};

template <class T>
class my_unique_ptr<T[]>
{
private:
	T * _ptr = nullptr;

public:
	my_unique_ptr() : _ptr(nullptr) {}
	my_unique_ptr(T * ptr) : _ptr(ptr) {}
	my_unique_ptr(const my_unique_ptr & obj) = delete; // copy constructor is deleted
	my_unique_ptr(my_unique_ptr && dyingObj) // move constructor
	{
		cleanup(); // cleanup any existing data

		// Transfer ownership of the memory pointed by dyingObj to this object
		_ptr = dyingObj._ptr;
		dyingObj.ptr = nullptr;
	}

	~my_unique_ptr() {
		cleanup();
	}

	my_unique_ptr& operator=(const my_unique_ptr & obj) = delete; // copy assignment is deleted
	void operator=(my_unique_ptr && dyingObj) // move assignment
	{
		cleanup(); // cleanup any existing data

		// Transfer ownership of the memory pointed by dyingObj to this object
		_ptr = dyingObj._ptr;
		dyingObj.ptr = nullptr;
	}

	T* operator->() { return _ptr; }
	T& operator*() { return *(_ptr); }

	T& operator[](int index){
		if(index < 0){
			throw("Negative index exception");
		}
		return _ptr[index]; // doesn't check out of bounds
	}

private:
	void cleanup(){
		if (_ptr != nullptr)
			delete[] _ptr;
	}
};

//----------- Testing -----------//
class Data
{
public:
    Data(size_t id) : _id{id}{}
    ~Data() { std::cout<<"inside Data's destructor\n"; }
private:
    size_t _id;
};

int main()
{
    // creates a my_unique_ptr object holding a 'Box' object
    my_unique_ptr<Data> box1(new Data{1541});
    // creates a my_unique_ptr object holding an array of 'Box' objects
    my_unique_ptr<Data[]> dataArr(new Data[3]{1476,9873,8764});
    Data d1 = dataArr[0]; // index based access
    return 0;
}