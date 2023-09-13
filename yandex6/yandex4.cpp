#include <iostream>

bool	check(size_t d, size_t w, size_t h, size_t a, size_t b, size_t n) {
	size_t n1, n2, n3, n4;

	n1 = w / (a + 2 * d);
	n2 = h / (b + 2 * d);
	n3 = w / (b + 2 * d);
	n4 = h / (a + 2 * d);

	if (n1 * n2 > n3 * n4)
		return n2 * n1 >= n;
	else
		return n3 * n4 >= n;
}

int main() {
	size_t n, a, b, w, h, d = 0;
	std::cin >> n >> a >> b >> w >> h;

	size_t l = 0, r = std::max(w, h), m;
	while (l != r) {
		m = (l + r + 1) / 2;
		if (check(m, w, h, a, b, n))
			l = m;
		else
			r = m - 1;
	}
	std::cout << l;
}