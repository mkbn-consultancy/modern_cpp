//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
//based on example in:
//https://www.codeproject.com/Tips/1244491/Cplusplus-Compile-time-Conditional-Types
//compilation line: -std=c++17 .\9_conditional_check_endian.cpp

#include <type_traits>
#include <iostream>

struct SizeOf1 { SizeOf1() { std::cout << "Size:1" << std::endl; } };
struct SizeOf2 { SizeOf2() { std::cout << "Size:2" << std::endl; } };
struct SizeOf4 { SizeOf4() { std::cout << "Size:4" << std::endl; } };
struct SizeOf8 { SizeOf8() { std::cout << "Size:8" << std::endl; } };
struct UnknownSize { UnknownSize() { std::cout << "Size:Unknown" << std::endl; } };

enum class Endian
{
	Big,
	Little
};
using BigEndian = std::integral_constant<Endian, Endian::Big>;
using LittleEndian = std::integral_constant<Endian, Endian::Little>;

template <class T>
using number_type =
typename std::conditional<
	sizeof(T) == 1, 
	SizeOf1, 
	typename std::conditional<	
		sizeof(T) == 2,
		SizeOf2,
		typename std::conditional<	
			sizeof(T) == 4,
			SizeOf4,
			typename std::conditional<	
				sizeof(T) == 8,
				SizeOf8,
				UnknownSize	
			>::type
		>::type
	>::type
>::type;


template<typename T>
void swap_endian(T& ui, UnknownSize)
{
}


template<typename T>
void swap_endian(T& ui, SizeOf1)
{
}

template<typename T>
void swap_endian(T& ui, SizeOf8)
{
	union EightBytes
	{
		T ui;
		uint8_t arr[8];
	};

	EightBytes fb;
	fb.ui = ui;
	// swap the endian
	std::swap(fb.arr[0], fb.arr[7]);
	std::swap(fb.arr[1], fb.arr[6]);
	std::swap(fb.arr[2], fb.arr[5]);
	std::swap(fb.arr[3], fb.arr[4]);

	ui = fb.ui;
}

template<typename T>
void swap_endian(T& ui, SizeOf4)
{
	union FourBytes
	{
		T ui;
		uint8_t arr[4];
	};

	FourBytes fb;
	fb.ui = ui;
	// swap the endian
	std::swap(fb.arr[0], fb.arr[3]);
	std::swap(fb.arr[1], fb.arr[2]);

	ui = fb.ui;
}

template<typename T>
void swap_endian(T& ui, SizeOf2)
{
	union TwoBytes
	{
		T ui;
		uint8_t arr[2];
	};

	TwoBytes fb;
	fb.ui = ui;
	// swap the endian
	std::swap(fb.arr[0], fb.arr[1]);

	ui = fb.ui;
}

template<typename T>
void swap_if_arithmetic(T& val, std::true_type)
{
	//number_type will be the struct according to its size
	swap_endian(val, number_type<T>());
}

template<typename T>
void swap_if_arithmetic(T& val, std::false_type)
{
	// T is not arithmetic so do nothing
}

template<typename T>
void swap(T& val, std::false_type) // false_type means different endian, therefore must swap
{
	std::cout<<"different endian, swapping.\n";

	std::is_arithmetic<T> is_arithmetic_type;

	swap_if_arithmetic(val, is_arithmetic_type);
}

template<typename T>
void swap(T& val, std::true_type)
{
	std::cout<<"same endian so do nothing.\n";
}

template<typename T>
constexpr bool isLittleEndian(T& t)
{
	constexpr char c[sizeof(T)]{ 1 };
	constexpr T i{ 1 };
	return i==c[0];
}

int main()
{
	int num1 = 1;

	swap(num1, std::integral_constant<bool, isLittleEndian(num1)>());
	swap(num1, std::integral_constant<bool, !isLittleEndian(num1)>());

	long long num2 = 1;
	swap(num2, std::integral_constant<bool, isLittleEndian(num2)>());
	swap(num2, std::integral_constant<bool, !isLittleEndian(num2)>());

    return 0;
}