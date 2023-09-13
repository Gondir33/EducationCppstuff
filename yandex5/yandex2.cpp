#include <iostream>
#include <vector>

int main() {
	int K, N;
	int	ans = 0;
	std::cin >> N >> K;
	std::vector<int>	v(N);
	int sum = 0;

	for (int i = 0; i < v.size(); ++i)
		std::cin >> v[i];
	int l = 0, r = 0;
	while (r < v.size()) {
		sum += v[r];
		while (sum > K) {
			sum -= v[l];
			++l;
		}
		if (sum == K) {
			++ans;
			++r;
			sum -= v[l];
			++l;
		} else
			++r;
	}
	std::cout << ans;
}