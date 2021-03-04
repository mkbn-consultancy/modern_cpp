#include <iostream>
#include <vector>
#include <algorithm>

struct sumUp {
	int& _sum;
public:
	sumUp(int sum) : _sum(sum) {}
	void operator()(int x) {
		_sum += x;
	}
};

int mainLambda() {
	std::vector<int> vec{ 1,2,3,4,5,6,7,8 };
	int sum = 0;
	std::for_each(vec.begin(), vec.end(), 
		[](int x)  {
		int isOdd = (x % 2);
		std::cout << x << "is " << (isOdd ? "odd" : "even") << ".\n";
		return isOdd;
	});
	std::cout << "sum of elements: " << sum << "\n";

	return 0;
}


