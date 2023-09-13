#include <iostream>
#include <vector>

int main(void) {
	std::vector<int>	a(10);
	std::vector<int>	min_dist(10);
	int					l ,r;
	for (auto& it : a) {
		std::cin >> it;
	}
	for (int i = 0; i < 10; ++i) {
		if (a[i] == 1) {
			l = i;
			r = i;
			while (l >= 0 && a[l] != 2) --l;
			while (r < 10 && a[r] != 2) ++r;
			if (l >= 0 && r < 10) {
				if (i - l > r - i)
					min_dist[i] = r - i;
				else
					min_dist[i] = i - l;
			} else if (r >= 10) {
				min_dist[i] = i - l;
			} else {
				min_dist[i] = r - i;
			}
		}
	}
	int max = min_dist[0];
	for (int i = 1; i < 10; ++i) {
		if (max < min_dist[i])
			max = min_dist[i];
	}
	std::cout << max;
	
}