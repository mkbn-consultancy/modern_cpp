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

int main() {
	std::vector<int> vec{ 1,2,3,4,5,6,7,8 };
	int sum = 0;
	std::for_each(vec.begin(), vec.end(), 
		[&sum](int x)  {
			sum+=x;
		});
	std::cout << "sum of elements: " << sum << "\n";

	return 0;
}


