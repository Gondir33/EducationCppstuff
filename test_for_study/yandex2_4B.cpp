#include <iostream>
#include <vector>


int main() {
	int L, K, tmp;
	std::cin >> L >> K;
	std::vector<bool>	vec(L);

	for (int i = 0; i < K; ++i) {
		std::cin >> tmp;
		vec[tmp] = true;
	}
	int r_last, l_last;
	tmp = L / 2;
	for (int i = 0; i <= tmp; ++i) {
		if (vec[i] == true)
			r_last = i;
	}
	for (int i = vec.size() - 1; i >= tmp; --i) {
		if (vec[i] == true)
			l_last = i;
	}
	if (l_last == r_last)
		std::cout << l_last;
	else {
		std::cout << r_last << l_last;
	}
}