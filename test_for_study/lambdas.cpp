#include <iostream>
#include <algorithm>
#include <vector>
/*
struct Compare {
	bool operator()(int x, int y) const {
		return std::abs(x - 5) < std::abs(y - 5);
	}
};
*/
//Capture list

int main(int argc, char const *argv[])
{
	std::vector<int> v{4, 5, 3, 6,8,9,0,12,5,876,32,3,2,-5};
	// std::sort(v.begin(), v.end(), Compare());
	int	a = 5;
	int b = 10;

	[&a, b](int x) mutable {//[=] - забирает все переменные, mutable - для изменения capture args
		std::cout << x + a << '\n';
		++a;
	}(5);
	
	std::cout << a << '\n';

	auto f = [](int x, int y) {
		return std::abs(x - 5) < std::abs(y - 5);
	};
	std::sort(v.begin(), v.end(), f);
	for (const auto& x : v) {
		std::cout << x << ' ';
	}
	return 0;
}
