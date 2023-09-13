#include <iostream>

int main( void )
{
	int x, y, z;
	std::cin >> x >> y >> z;

	if (z % 4 == 0) {
		if ((x == 2 && (y <= 29 && y > 12)) || (y == 2 && (x <= 29 && x > 12))) {
			std::cout << 1;
			return 0;
		}
	} else {
		if ((x == 2 && y == 29) || (y == 2 && x == 29)) {
			std::cout << 0;
			return 0;
		}
	}
	if ((x == 2 && (y <= 28 && y > 12)) || (y == 2 && (x <= 28 && x > 12))) {
		std::cout << 1;
		return 0;
	}
	if (x <= 7) {
		if ((x % 2 == 1) && (y <= 31 && y > 12)) {
			std::cout << 1;
			return 0;
		}
		if ((x % 2 == 0) && (y <= 30 && y > 12)) {
			std::cout << 1;
			return 0;
		}
	}
	if (y <= 7) {
		if ((y % 2 == 1) && (x <= 31 && x > 12)) {
			std::cout << 1;
			return 0;
		}
		if ((y % 2 == 0) && (x <= 30 && x > 12)) {
			std::cout << 1;
			return 0;
		}
	}
	if (y > 7 && y <= 12) {
		if ((y % 2 == 0) && (x <= 31 && x > 12)) {
			std::cout << 1;
			return 0;
		}
		if ((y % 2 == 1) && (x <= 30 && x > 12)) {
			std::cout << 1;
			return 0;
		}
	}
	if (x > 7 && x <= 12) {
		if ((x % 2 == 0) && (y <= 31 && y > 12)) {
			std::cout << 1;
			return 0;
		}
		if ((x % 2 == 1) && (y <= 30 && y > 12)) {
			std::cout << 1;
			return 0;
		}
	}
	if (x == 12 && y == 12) {
		std::cout << 1;
		return 0;
	}
	std::cout << 0;
	return 0;
	
}
