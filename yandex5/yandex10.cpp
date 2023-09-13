#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>


long long calcDist(long long x1, long long y1, long long x2, long long y2) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
	int N; std::cin >> N;
	long long ans = 0;
	std::vector<std::vector<long long>>	v(N);
	std::set<std::array<long long, 2>>	used;
	std::vector<long long>	dis;
	long long tmp1, tmp2;
	long long l, r;

	for (int i = 0; i < N; ++i) {
		std::cin >> tmp1 >> tmp2;
		v[i] = {tmp1, tmp2};
	}

	dis.reserve(N);
	for (int i = 0; i < N; ++i) {
		dis.clear();
		used.clear();
		for (int j = 0; j < N; ++j) {
			tmp1 = v[j][0] - v[i][0];
			tmp2 = v[j][1] - v[i][1];
			dis.push_back(tmp1 * tmp1 + tmp2 * tmp2);
			if (used.count({tmp1, tmp2}) == 1)
				--ans;
			used.insert({-tmp1, -tmp2});
		}
		std::sort(dis.begin(), dis.end());
		l = 0; r = 0;
		while (l < dis.size()) {
			while (r < dis.size() && dis[l] == dis[r])
				++r;
			ans += (r - l - 1);
			++l;
		}
	}
	std::cout << ans;
}