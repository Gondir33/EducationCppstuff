#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, k, tmp;
	size_t ans = 0;
	std::cin >> n >> k;
	std::vector<int>	v;
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	int l = 0;
	int r = 2;
	while (r < v.size()) {
		if (r - l >= 2) {
			if (v[l] * k < v[r]) {
				if (v[l] == v[r])
					++ans;
				else 
					ans +=3;
				++r;
			} else
				++l;
		}
		else
			++r;
	}
	std::cout << ans;

}

/*

k = 50

1 1 1 2 2 2 3 3 3 4 4 5 6 7 8 9 10
*/