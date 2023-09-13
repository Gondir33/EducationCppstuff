#include <iostream>

int main() {
	int		w, h, n;
	std::cin >> w >> h >> n;
	size_t	min = std::min(w, h), max = std::max(w, h);
	size_t	sum_min = 0, sum_max = max;

	while (n > 0) {
		sum_min += min;
		n -= sum_max / max;
		if (n <= 0)
			break;
		if (sum_min + min > sum_max + max) {
			sum_max += max;
			n -= sum_min / min;
		}
	}
	std::cout << std::max(sum_min, sum_max);
}