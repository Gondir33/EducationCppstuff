#include <iostream>
#include <vector>
#include <algorithm>

bool	check(std::vector<int>& v, int m, int R, int C) {
	int i = 0, ans = 0;
	while (i < v.size() - C + 1) {
		if (v[i + C - 1] - v[i] <= m) {
			++ans;
			i += C;
		} else
			++i;
	}
	return ans >= R;
}

int main() {
	int N, R, C;
	std::cin >> N >> R >> C;
	std::vector<int>	v(N);
	std::vector<int>	ans(N - C + 1);
	for (auto& it : v)
		std::cin >> it;
	std::sort(v.begin(), v.end());
	int l = 0, r = v[v.size() - 1], m;
	while (l < r) {
		m = (l + r) / 2;
		if (check(v, m, R, C)) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	std::cout << l;
}