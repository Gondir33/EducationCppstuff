#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

#define POINT	-1
#define END		1

int main() {
	int d , n, tmp;
	std::cin >> n >> d;
	std::vector<std::vector<int>>	v;
	std::vector<int>				p;
	std::unordered_map<int, int>	ans;
	std::set<int>					PoolVariant;
	for (int i = 0; i < n; ++i) {
		std::cin >> tmp;
		v.push_back({tmp, POINT});
		v.push_back({tmp + d, END});
		p.push_back(tmp);
	}
	
	std::sort(v.begin(), v.end());
	int max = 0;

	for (int i = 1; i <= n; ++i)
		PoolVariant.insert(i);

	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i][1] == POINT) {
			ans[v[i][0]] = *PoolVariant.begin();
			max = std::max(max, *PoolVariant.begin());
			PoolVariant.erase(PoolVariant.begin());
		} else if (v[i][1] == END) {
			PoolVariant.insert(ans[v[i][0] - d]);
		}
	}
	std::cout << max << '\n';
	for (auto& it : p)
		std::cout << ans[it] << ' ';

}