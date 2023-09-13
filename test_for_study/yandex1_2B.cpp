#include <iostream>
#include <cmath>

int main( void )
{
	int N, i, j, n1, n2;

	std::cin >> N >> i >> j;

	if (j > i) {
		n1 = j - i - 1;
		n2 = (N - j) + i - 1;
	} else {
		n1 = i - j - 1;
		n2 = (N - i) + j - 1;
	}
	if (n2 < n1) {
		std::cout << n2;
	} else {
		std::cout << n1;
	}
	return 0;
}
