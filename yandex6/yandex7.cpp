#include <iostream>

int main() {
	long long	n, m, t;
	std::cin >> n >> m >> t;

	long long l = 0, r = std::min(n, m), mid, res;
	while (l < r) {
		mid = (l + r + 1) / 2;
		res = mid * (2 * n + 2 * m - 4 * mid);
		if (res < t)
			l = mid;
		else if (res == t) {
			l = mid;
			break;
		}
		else
			r = mid - 1;
	}
	if (res == t) {
		while (l * (2 * n + 2 * m - 4 * l) == t)
			--l;
		++l;
	}
	std::cout << l;
}
