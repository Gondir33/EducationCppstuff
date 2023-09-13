#include <iostream>
#include <vector>

struct coord {
	int x;
	int y;
};


int main() {
	int	t, d, n, tmp;
	std::cin >> t >> d >> n;
	std::vector<coord>	v(n);
	std::vector<int>	f(8); // curr: 0:min(x-y) 1:max(x-y) 2:min(x + y) 3:max(x + y)\\t				next: 4:min(x-y) 5:max(x-y) 6:min(x + y) 7:max(x + y)\\d
	for (int i = 0; i < v.size(); ++i) {
		std::cin >> tmp;
		v[i].x = tmp;
		std::cin >> tmp;
		v[i].y = tmp;
	}
	
	f[0] = 0;
	f[1] = 0;
	f[2] = 0;
	f[3] = 0;
	
	for (int i = 0; i < v.size(); ++i) {
		f[0] = f[0] - t;
		f[1] = f[1] + t;
		f[2] = f[2] - t;
		f[3] = f[3] + t;
		f[4] = v[i].x - d - v[i].y;
		f[5] = v[i].x + d - v[i].y;
		f[6] = v[i].x - d + v[i].y;
		f[7] = v[i].x + d + v[i].y;
		f[0] = std::max(f[0], f[4]);
		f[1] = std::min(f[1], f[5]);
		f[2] = std::max(f[2], f[6]);
		f[3] = std::min(f[3], f[7]);	
	}
	std::vector<coord>	ans;
	for (int i = f[0]; i <= f[1]; ++i) {
		for (int j = f[2]; j <= f[3]; ++j) {
			if ((i + j) % 2 == 0) {
				int x = (i + j) / 2;
				int y = j - x;
				ans.push_back({x, y});
			}
		}
	}
	std::cout << ans.size() << '\n';
	for (auto& it : ans) {
		std::cout << it.x << ' ' << it.y << '\n';
	}
}