#include <iostream>

int main( ) {
	int a, b, c;
	std::cin >> a >> b >> c;

	if (a + b <= c) {
		std::cout << "NO";
	} else if (a + c <= b) {
		std::cout << "NO";
	} else if (b + c <= a) {
		std::cout << "NO";
	} else {
		std::cout << "YES";
	}
}