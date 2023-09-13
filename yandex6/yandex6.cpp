#include <iostream>

bool	check(int N, int x, int y, int m ) {
	return m / x + m / y >= N;
}

int main() {
	int N, x, y;
	std::cin >> N >> x >> y;
	size_t ans = std::min(x, y);
	
	--N;
	size_t l = 0, r = N * std::max(x, y), m;
	while (l < r) {
		m = (l + r) / 2;
		if (check(N, x, y, m))
			r = m;
		else
			l = m + 1; 
	}
	std::cout << ans + l;
}