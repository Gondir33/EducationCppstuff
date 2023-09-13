#include <iostream>

bool	check(size_t a, size_t b, size_t c, size_t m) {
	return static_cast<long double>(a * 2 + b * 3 + c * 4 + m * 5) / static_cast<long double>(a + b + c + m) >= 3.5;
}

int main() {
	size_t	a, b, c;
	std::cin >> a >> b >> c;

	size_t	l = 0, r = a + b + c, m;
	while (l < r) {
		m = (l + r) / 2;
		if (check(a, b, c, m))
			r = m;
		else
			l = m + 1;
	}
	std::cout << l;
}