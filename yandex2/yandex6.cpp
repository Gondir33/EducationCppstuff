#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<int>	v(N), ans;

	for (auto& it : v)
		std::cin >> it;

	int i = 0;
	int j = v.size() - 1;
	while (i <= j) {
		if (v[i] != v[j]) {
			j = v.size() - 1;
		} else {
			--j;
		}
		++i;
	}
	while (i < v.size() && v[i] == v[j]) {
		--j;
		++i;
	}
	while (j >= 0) {
		ans.push_back(v[j]);
		--j;
	}
	std::cout << ans.size() << '\n';
	for (auto& it : ans)
		std::cout << it << ' ';
}