#include <iostream>

int main() {
	int a, b ,c;
	std::cin >> a >> b >> c;

	if (c < 0) {
		std::cout << "NO SOLUTION";
	} else if (a == 0 && b == c * c) {
		std::cout << "MANY SOLUTIONS";
	} else if (a == 0 && b != c * c) {
		std::cout << "NO SOLUTION";
	} else if ((c * c - b) % a != 0) {
		std::cout << "NO SOLUTION";
	} else {
		std::cout << (c * c - b) / a;
	}
}