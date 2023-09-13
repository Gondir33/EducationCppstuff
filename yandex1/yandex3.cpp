#include <iostream>
#include <vector>

int main() {
	std::vector<std::string>	s(4);
	std::vector<std::string>	k(4);

	for (auto& it : s) {
		std::cin >> it;
		if (it[0] == '+')
			it[1] = '8';
	}
	for (int i = 0; i < 4; ++i) {
		int count = 0;
		for (int j = 0; j < s[i].size(); ++j) {
			if (s[i][j] >= '0' && s[i][j] <= '9') {
				++count;
				k[i].push_back(s[i][j]);
			}
		}
		if (count == 7)
			k[i].insert(0, "8495");
	}
	for (int i = 1; i < 4; ++i) {
		if (k[0] == k[i]) 
			std::cout << "YES" << '\n';
		else
			std::cout << "NO" << '\n';
	}

}