#include <iostream>

int main( void )
{
	int	a, b ,c ,d;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	
	if (a == 0 && b == 0) {
		std::cout << "INF";
		return 0;
	}
	if ( a == 0 || b % a != 0) {
		std::cout << "NO";
		return 0;
	}
	if (c == 0) {
		std::cout << -b / a;
		return 0;
	}

	if ( (-d / c == -b / a) && (-d % c == -b % a) ) {
		std::cout << "NO";
		return 0;
	}
	std::cout << -b / a;
	return 0;
}
