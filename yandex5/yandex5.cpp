#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
	int n, k, dis = INT32_MAX;
	std::cin >> n >> k;
	std::vector<int>	v(n + 1);
	std::unordered_map<int, int>	mp;
	for (int i = 1; i < v.size(); ++i)
		std::cin >> v[i];

	int l = 1, r = 1, ansL = 0, ansR = 0;
	while (r < v.size()) {
		++mp[v[r]];
		while (mp.size() == k) {
			if (r - l < dis) {
				dis = r - l;
				ansL = l;
				ansR = r;
			}
			--mp[v[l]];
			if (mp[v[l]] == 0)
				mp.erase(v[l]);
			++l;
		}
		++r;
	}
	std::cout << ansL << ' ' << ansR;
}