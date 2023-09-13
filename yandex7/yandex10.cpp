#include <iostream>
#include <vector>

struct coord {
	int x;
	int y;
};


int main() {
	int	t, d, n, tmp;
	std::cin >> t >> d >> n;
	std::vector<coord>	v(n + 1);
	std::vector<int>	f(8); // 0:min(x-y) 1:min(x-y)
	v[0].x = 0;
	v[0].y = 0;
	for (int i = 1; i < v.size(); ++i) {
		std::cin >> tmp;
		v[i].x = tmp;
		std::cin >> tmp;
		v[i].y = tmp;
	}
	for (int i = 0; i < v.size(); ++i) {

	}

}