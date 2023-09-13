#include <iostream>
#include <unordered_map>

int main() {
	int n, k, tmp;
	std::cin >> n;
	std::unordered_map<int, int>	mp;
	
	for (int i = 1; i <= n; ++i) {
		std::cin >> tmp;
		mp[i] = tmp;
	}
	std::cin >> k;
	for (int i = 0; i < k; ++i) {
		std::cin >> tmp;
		--mp[tmp];
	}
	for (int i = 1; i <= n; ++i) {
		if (mp[i] >= 0)
			std::cout << "NO\n";
		else
			std::cout << "YES\n";
	}
}