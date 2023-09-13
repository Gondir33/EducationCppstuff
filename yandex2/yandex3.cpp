#include <iostream>
#include <vector>
#include <cmath>

int main() {
	int N;
	int x;
	std::cin >> N;
	std::vector<int>	v(N);
	for (auto& it : v) {
		std::cin >> it;
	}
	
	std::cin >> x;

	int dis = std::abs(v[0] - x);
	int ans = x;
	for (int i = 0; i < v.size(); ++i) {
		if (std::abs(v[i] - x) <= dis) {
			ans = v[i];
			dis = std::abs(v[i] - x);
		}
	}

	std::cout << ans;
	return 0;
}