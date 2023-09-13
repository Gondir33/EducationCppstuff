#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
	int m, n, tmp1, tmp2;
	std::cin >> n >> m;
	std::vector<std::vector<int>>	v;
	std::vector<int>				p;
	std::unordered_map<int, int>	ans;
	for (int i = 0; i < n; ++i) {
		std::cin >> tmp1 >> tmp2;
		v.push_back({std::min(tmp1, tmp2), -1});
		v.push_back({std::max(tmp1, tmp2), 1});
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> tmp1;
		p.push_back(tmp1);
		v.push_back({tmp1, 0});
	}
	std::sort(v.begin(), v.end());
	int online = 0;
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i][1] == -1)
			++online;
		else if (v[i][1] == 1)
			--online;
		else
			ans[v[i][0]] = online;
	}
	for (auto& it : p)
		std::cout << ans[it] << ' ';
}