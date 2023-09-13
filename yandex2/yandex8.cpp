#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

void	solution(std::vector<int> v) {
	long long min1, min2, max1, max2, max3;

	std::sort(v.begin(), v.begin() + 3);
	min1 = v[0];
	min2 = v[1];
	max1 = v[2];
	max2 = v[1];
	max3 = v[0];
	for (int i = 3; i < v.size(); ++i) {
		if (max1 < v[i]) {
			max3 = max2;
			max2 = max1;
			max1 = v[i];
		} else if (max2 < v[i]) {
			max3 = max2;
			max2 = v[i];
		} else if (max3 < v[i]) {
			max3 = v[i];
		}
		if (min1 > v[i]) {
			min2 = min1;
			min1 = v[i];
		} else if (min2 > v[i]) {
			min2 = v[i];
		}
	}
	if (min1 * min2 * max1 > max1 * max2 * max3) {
		std::cout << min1 << ' ' << min2 << ' ' << max1;
	} else {
		std::cout << max2 << ' ' << max1 << ' ' << max3;
	}


}

int main() {
	std::vector<int>	v;
	std::string			s;
	std::ifstream	in("input.txt");
	if (in.is_open())
		std::getline(in, s);
	in.close();
	int j;
	for (int i = 0; i < s.size(); ++i) {
		j = 0;
		while (s[i + j] != ' ' && s[j + i] != '\n' && j + i < s.size()) ++j;
		v.push_back(std::stoi(s.substr(i, j)));
		i = j + i;
	}
	solution(v);
}