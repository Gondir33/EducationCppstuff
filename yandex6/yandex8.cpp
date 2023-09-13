#include <iostream>
#include <vector>

bool check(int K, std::vector<int>& v, int m) {
	size_t sum = 0;
	for (auto& it : v)
		sum += it / m;
	return sum >= K;
}

int main() {
	int N, K;
	size_t sum = 0;
	std::cin >> N >> K;
	std::vector<int>	v(N);
	for (auto& it : v)
		std::cin >> it;
	int l = 0, r = 10'000'000, m;
	while (l < r) {
		m = (l + r + 1) / 2;
		if (check(K, v, m))
			l = m;
		else
			r = m - 1;
	}
	std::cout << l;
}
