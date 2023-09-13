#include <iostream>

int main() {
	int N, K, M;
	std::cin >> N >> K >> M;
	int count = 0;
	int i;

	if (M > K) {
		std::cout << 0;
	} else if (K > N) {
		std::cout << 0;
	} else {
		while (N - K >= 0) {
			i = 1;
			while (M * i <= K)
				++i;
			--i;
			count += i;
			N -= M * i;
		}
		std::cout << count;
	}
}