#include <iostream>
#include <vector>

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;
	std::vector<std::vector<int>>	v(K);
	std::vector<std::vector<char>>	f(N + 2);
	for (auto& it : f)
		it.resize(M + 2);
	int tmp;
	for (auto& it : v) {
		std::cin >> tmp;
		it.push_back(tmp);
		std::cin >> tmp;
		it.push_back(tmp);
	}
	int count;
	for (const auto& it : v)
		f[it[0]][it[1]] = '*';
	for (int i = 1; i < f.size() - 1; ++i) {
		for (int j = 1; j < f[i].size() - 1; ++j) {
			if (f[i][j] != '*') {
				count = 0;
				if (f[i - 1][j - 1] == '*')
					++count;
				if (f[i - 1][j] == '*')
					++count;
				if (f[i - 1][j + 1] == '*')
					++count;
				if (f[i][j - 1] == '*')
					++count;
				if (f[i][j + 1] == '*')
					++count;
				if (f[i + 1][j - 1] == '*')
					++count;
				if (f[i + 1][j] == '*')
					++count;
				if (f[i + 1][j + 1] == '*')
					++count;
				f[i][j] = '0' + count;
			}
		}
	}
	for (int i = 1; i < f.size() - 1; ++i) {
		for (int j = 1; j < f[i].size() - 1; ++j) {
			std::cout << f[i][j] << ' ';
		}
		std::cout << '\n';
	}
}