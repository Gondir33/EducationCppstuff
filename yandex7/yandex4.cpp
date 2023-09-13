#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

#define	COME	-1
#define LEAVE	1
#define VIDEO_LENGTH	4

int main() {
	int N, tmp1, tmp2;
	std::cin >> N;
	std::vector<std::vector<int>>	v;
	v.reserve(N * 2);
	for (size_t i = 0; i < N * 2; i += 2) {
		std::cin >> tmp1 >> tmp2;
		if (tmp2 - tmp1 >= VIDEO_LENGTH) {
			v.push_back({tmp1, COME});
			v.push_back({tmp2 - VIDEO_LENGTH, LEAVE});
		}
	}
	if (v.size() == 2) {
		std::cout << 1 << ' ' << v[0][0] << ' ' << v[0][0] + VIDEO_LENGTH + 1 << '\n';
	} else if (v.size() == 0) {
		std::cout << 0 << ' ' << 1 << ' ' << 6 << '\n';
	} else {
		std::sort(v.begin(), v.end());
		int online, tmpmax1, tmpmax2, max1 = 0, max2 = 0, i, ans1, ans2, tmptime;
		for (size_t j = 0; j < v.size(); ++j) {
			i = 0;
			online = 0;
			tmpmax1 = 0;
			tmpmax2 = 0;
			while (i < v.size() && v[i][0] <= v[j][0]) {
				if (v[i][1] == COME)
					++online;
				else if (v[i][1] == LEAVE && v[i][0] != v[j][0])
					--online;
				++i;
			}
			tmpmax1 = online;
			online = 0;
			while (i < v.size() && v[i][0] - VIDEO_LENGTH <= v[j][0])
				++i;
			while (i < v.size()) {
				if (v[i][1] == COME)
					++online;
				if (online > tmpmax2) {
					tmpmax2 = online;
					tmptime = v[i][0];
				}
				if (v[i][1] == LEAVE)
					--online;
				++i;
			}
			if (tmpmax1 + tmpmax2 > max1 + max2) {
				max1 = tmpmax1;
				ans1 = v[j][0];
				max2 = tmpmax2;
				ans2 = tmptime;
			}
		}
		std::cout << max1 + max2 << ' ' << ans1 << ' ' << ans2 << '\n';
	}
}