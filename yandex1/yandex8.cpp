#include <iostream>

int main() {
	int a, b, n, m;
	std::cin >> a >> b >> n >> m;
	int max_time_a, max_time_b, min_time_a, min_time_b;

	max_time_a = n + a * (n + 1);
	max_time_b = m + b * (m + 1);
	min_time_a = n + a * (n - 1);
	min_time_b = m + b * (m - 1);

	if (max_time_a < min_time_b || max_time_b < min_time_a) {
		std::cout << -1;
	} else {
		std::cout << std::max(min_time_a, min_time_b) << ' ' << std::min(max_time_a, max_time_b);
	}
}