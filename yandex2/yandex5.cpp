#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<int>	v(N);
	for (auto& it : v)
		std::cin >> it;
	int max1 = INT32_MIN; 
	int max2 = INT32_MIN; 
	int max3 = INT32_MIN;
	int min = INT32_MAX;
	int mini = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > max1) {
			max3 = max2;
			max2 = max1;
			max1 = v[i];
		} else if (v[i] > max2) {
			max3 = max2;
			max2 = v[i];
		} else if (v[i] > max3) {
			max3 = v[i];
		}
		if (min > v[i]) {
			min = v[i];
			mini = i;
		}
	}
	int max = INT32_MIN;
	bool flag = false;
	for (int i = 0; i < v.size() - 1; ++i) {
		if (flag == true) {
			if (v[i] % 10 == 5) {
				if (v[i + 1] == min) {
					if (v[i] > max)
						max = v[i];
				}
			}
		}
		if (v[i] == max1 || v[i] == max2 || v[i] == max3)
			flag = true;
	}
	if (max == INT32_MIN) {
		std::cout << 0;
		return 0;
	}
	int i = 0, ans = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > max)
			++ans;
	}
	std::cout << ++ans;
}