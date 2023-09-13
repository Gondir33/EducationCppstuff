#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

#define OPEN		-1
#define CLOSE		1
#define END_DAY		24*60
#define	START_DAY	0

int main() {
	int N, t1, t2, t3, t4;
	std::cin >> N;
	std::vector<std::vector<int>>	events;
	events.reserve(N * 3);
	for (int i = 0; i < N; ++i) {
		std::cin >> t1 >> t2 >> t3 >> t4;
		t1 = t1 * 60 + t2;
		t3 = t3 * 60 + t4;
		if (t3 - t1 == 0) {
			events.push_back({START_DAY, OPEN});
			events.push_back({END_DAY, CLOSE});
		} else if (t3 - t1 < 0) {
			events.push_back({START_DAY, OPEN});
			events.push_back({t3, CLOSE});
			events.push_back({t1, OPEN});
			events.push_back({END_DAY, CLOSE});
		} else {
			events.push_back({t1, OPEN});
			events.push_back({t3, CLOSE});
		}
	}
	int online = 0, ans = 0;
	std::sort(events.begin(), events.end());
	for (size_t i = 0; i < events.size(); ++i) {
		if (events[i][1] == OPEN) {
			++online;
		} else {
			if (online == N)
				ans += events[i][0] - events[i - 1][0];
			--online;
		}
	}
	std::cout << ans << '\n';

}