#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
// задача на префиксные суммы или нет?

int main() {
	int 	N, tmp1, tmp2, M;
	std::cin >> N;
	std::vector<std::vector<int>> v1;
	v1.reserve(N);
	std::vector<std::vector<int>> v2;
	int j;
	
	for (int i = 0; i < N; ++i) {
		std::cin >> tmp1;
		std::cin >> tmp2;
		v1.push_back({tmp1, tmp2});
	}
	std::cin >> M;
	v2.reserve(M);
	for (int i = 0; i < M; ++i) {
		std::cin >> tmp1;
		std::cin >> tmp2;
		v2.push_back({tmp1, tmp2});
	}
	for (int i = 0; i < v2.size(); ++i) {

	}
}