#include <iostream>
#include <vector>

int main() {
	int 	n, dis;
	size_t	ans = 0;
	std::cin >> n >> dis;
	std::vector<int>	v(n);
	for (auto& it : v)
		std::cin >> it;
	int r = 0, l = 0;
	while (r < v.size()) {
		while (v[r] - v[l] > dis) {
			ans += v.size() - r;
			++l;
		}
		++r;
	}
	std::cout << ans;
}