#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, M, b, e;
	std::cin >> N >> M;
	std::vector<std::vector<int>>	v;
	for (size_t i = 0; i < M; ++i) {
		std::cin >> b >> e;
		v.push_back({b, -1});
		v.push_back({e, 1});
	}
	std::sort(v.begin(), v.end());
	int watch = 0, watched_people = 0;
	for (size_t i = 0; i < v.size(); ++i) {
		if (watch > 0)
			watched_people += v[i][0] - v[i - 1][0];
		if (v[i][1] == -1)
			++watch;
		else
			--watch;
		if (watch == 0)
			++watched_people;
	}
	std::cout << N - watched_people;
}