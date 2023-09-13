#include <iostream>
#include <vector>

int main() {
	int N, sum = 0;
	std::cin >> N;
	std::vector<int>	a(N);

	for (auto& it : a) {
		std::cin >> it;
	}
	int max = a[0], max_i = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] > max) {
			max = a[i];
			max_i = i;
		}
	}
	std::swap(a[max_i], a[N - 1]);
	--N;
	for (int i = 0; i < N; ++i) {
		sum += a[i];
	}
	std::cout << sum;
}