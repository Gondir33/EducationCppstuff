#include <iostream>
#include <unordered_map>

int main() {
	int n, tmp1, tmp2;
	std::cin >> n;
	std::unordered_map<int, int>	mp;
	
	for (int i = 1; i <= n; ++i) {
		std::cin >> tmp1 >> tmp2;
		if (tmp2 > mp[tmp1])
			mp[tmp1] = tmp2;
	}
	unsigned long long sum = 0;
	for (auto& it : mp) {
		sum += it.second;
	}
	std::cout << sum;
}