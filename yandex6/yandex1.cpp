#include <iostream>
#include <vector>
#include <algorithm>

bool	include(const std::vector<int>& v, const int& elem) {
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
	return v[l] == elem;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int>	v1(N), v2(K);
	for (auto& it : v1)
		std::cin >> it;
	for (auto& it : v2)
		std::cin >> it;

	std::sort(v1.begin(), v1.end(), [](int a, int b) {
		return (a < b);
	});

	for (int i = 0; i < v2.size(); ++i) {
		if (include(v1, v2[i]) == true)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}