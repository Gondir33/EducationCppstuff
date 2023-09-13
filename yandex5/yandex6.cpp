#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
	int n, m, tmp, tmp2, sum = 0;
	std::cin >> n;
	std::vector<int>	v(n);
	for (int i = 0; i < n; ++i)
		std::cin >> v[i];
	std::cin >> m;
	std::unordered_map<int, int>	mp;
	for (int i = 0; i < m; ++i) {
		std::cin >> tmp;
		std::cin >> tmp2;
		if (mp.count(tmp) == 1) {
			if (tmp2 < mp[tmp]) {
				mp[tmp] = tmp2;
			}
		}
		else
			mp[tmp] = tmp2;
	}
	for (int i = 0; i < n; ++i) {
		int min = INT32_MAX;
		for (auto& it : mp) {
			if (it.first >= v[i])
				if (it.second < min)
					min = it.second;
		}
		sum += min;
	}
	std::cout << sum;
}