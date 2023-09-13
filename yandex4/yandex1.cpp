#include <iostream>
#include <unordered_map>

int main() {
	int n;
	std::cin >> n;
	std::unordered_map<std::string, std::string>	hash;
	std::string tmp1, tmp2;
	for (int i = 0; i < n; ++i) {
		std::cin >> tmp1 >> tmp2;
		hash[tmp1] = tmp2;
	}
	std::cin >> tmp1;
	for (auto& it : hash) {
		if (it.first == tmp1) {
			std::cout << it.second;
		} else if (it.second == tmp1)
			std::cout << it.first;
	}
}