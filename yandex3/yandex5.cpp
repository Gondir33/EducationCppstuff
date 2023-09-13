#include <iostream>
#include <set>

int main() {
	int x, y, z, N, ans;
	std::cin >> x >> y >> z >> N;
	std::set<int>	set;
	while (N > 0) {
		set.insert(N % 10);
		N /= 10;
	}
	ans = set.count(x) + set.count(y) + set.count(z);
	std::cout << set.size() - ans;
}
