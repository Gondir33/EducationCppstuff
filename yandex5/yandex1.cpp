#include <iostream>
#include <vector>

int main() {
	int n, m, mini, minj, value = INT32_MAX, tmp;
	std::cin >> n;
	std::vector<int>	v1(n + 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> tmp;
		v1[i] = tmp;
	}
	v1[n] = INT32_MAX;
	std::cin >> m;
	std::vector<int>	v2(m + 1);
	for (int i = 0; i < m; ++i) {
		std::cin >> tmp;
		v2[i] = tmp;
	}
	v2[m] = INT32_MAX;
	int i = 0, j = 0;
	while ( i < v1.size() - 1 && j < v2.size() - 1 ) {
		if (std::abs(v1[i] - v2[j]) < value) {
			value = std::abs(v1[i] - v2[j]);
			mini = i;
			minj = j;
		}
		if (std::abs(v1[i] - v2[j]) > std::abs(v1[i] - v2[j + 1]))
			++j;
		else
			++i;
	}
	if (std::abs(v1[i] - v2[j]) < value ) {
		mini = i;
		minj = j;
	}
	std::cout << v1[mini] << ' ' << v2[minj];
}