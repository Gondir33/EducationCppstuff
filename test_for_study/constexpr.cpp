#include <iostream>
#include <array>

struct S {
	constexpr S() {}
	int		x = 0;
	double	d = 0;
};

constexpr int	factorial( int n ) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

int main( void ) {

	//c++17
	/*if constexpr (sizeof(int) == 4) {
		std::cout << 1 << '\n';
	}*/

	constexpr int y = factorial(5);

	std::cout << y << '\n';
}
