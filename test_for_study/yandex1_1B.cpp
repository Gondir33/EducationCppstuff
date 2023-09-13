#include <iostream>

int main( void )
{
	int	r, i, c;
	
	std::cin >> r;
	std::cin >> i;// интерактор
	std::cin >> c;// чекер

	if (i == 0 && r != 0) {
		std::cout << 3;
		return 0;
	} else if (i == 0 && r == 0) {
		std::cout << c;
		return 0;
	}
	if (i == 1) {
		std::cout << c;
		return 0;
	}
	if (i == 4 && r != 0) {
		std::cout << 3;
		return 0;
	} else if ( i == 4 && r == 0) {
		std::cout << 4;
		return 0;
	}
	if (i == 6) {
		std::cout << 0;
		return 0;
	}
	if (i == 7) {
		std::cout << 1;
		return 0;
	}
	std::cout << i;
	return 0;
}
