#include <iostream>
#include <set>
/*
struct isOdd {
	bool operator()(int x) {
		return x % 2;
	}
};
*/
template <class T>
size_t countIf(const int* arr, int n, T f) {
	size_t counter = 0;
	size_t i = 0;
	for (i = 0; i < n; ++i) {
		if (f(arr[i])) {
			++counter;
		}
	}
	return counter;
}

void testFunc() {
	int vec[] = { 1,2,3,4,5,6,7,8 };
	size_t result = countIf(vec, 8, [](int x) {return x % 2; });
	std::cout << result << std::endl;
}

