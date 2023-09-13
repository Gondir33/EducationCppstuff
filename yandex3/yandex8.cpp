#include <iostream>
#include <unordered_set>

int main() {
	int	N;
	std::unordered_set<int>	hash_set;
	int tmp1, tmp2;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> tmp1 >> tmp2;
		hash_set.insert(tmp1);
	}
	std::cout << hash_set.size();
}