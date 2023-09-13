#include <iostream>
#include <vector>
#include <algorithm>

size_t	include(const std::vector<int>& v, const int& elem) {
	size_t	l = 0;
	size_t	r = v.size() - 1;
	size_t	mid;
	
	while (l < r) {
		mid = (l + r) / 2;
		if (elem <= v[mid])
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int>	v1(N), v2(K);
	int index;

	for (auto& it : v1)
		std::cin >> it;
	for (auto& it : v2)
		std::cin >> it;

	std::sort(v1.begin(), v1.end(), [](int a, int b) {
		return (a < b);
	});

	for (int i = 0; i < v2.size(); ++i) {
		index = include(v1, v2[i]);
		if (index == 0) {
			std::cout << v1[index] << '\n';
		} else {
			if (std::abs(v1[index] - v2[i]) < std::abs(v1[index - 1] - v2[i]))
				std::cout << v1[index] << '\n';
			else
				std::cout << v1[index - 1] << '\n';
		}
	}
}