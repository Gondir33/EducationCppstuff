#include <iostream>
#include <unordered_map>

int main() {
	int N, M, n;
	std::cin >> N;
	std::string	s;
	std::unordered_map<std::string, int>	mp;
	for (int i = 0; i < N; ++i) {
		std::cin >> M;
		for (int j = 0; j < M; ++j) {
			std::cin >> s;
			++mp[s];
		}
	}
	n = 0;
	for (const auto& it : mp) {
		if (it.second == N)
			++n;
	}
	std::cout << n << '\n';
	for (const auto& it : mp) {
		if (it.second == N)
			std::cout << it.first << '\n';
	}
	std::cout << mp.size() << '\n';
	for (const auto& it : mp) {
			std::cout << it.first << '\n';
	}
}