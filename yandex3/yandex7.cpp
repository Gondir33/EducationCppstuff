#include <iostream>
#include <unordered_map>

int main() {
	int	N;
	std::cin >> N;
	std::unordered_map<int, int>	mp;
	int tmp1, tmp2;
	for (int i = 0; i < N; ++i) {
		std::cin >> tmp1;
		std::cin >> tmp2;
		tmp1 = std::abs(tmp1);
		tmp2 = std::abs(tmp2);
		if ((tmp1 + tmp2) == N - 1)
				mp[tmp1] = tmp2;
	}
	std::cout << mp.size();
}