#include <iostream>
#include <vector>
#include <fstream>

void	solution(std::vector<int> v) {
	long long min1, min2, max1, max2;

	if (v[0] > v[1]) {
		min1 = v[1]; min2 = v[0];
		max1 = v[0]; max2 = v[1];
	} else {
		min2 = v[1]; min1 = v[0];
		max2 = v[0]; max1 = v[1];
	}
	for (int i = 2; i < v.size(); ++i) {
		if (max1 < v[i]) {
			max2 = max1;
			max1 = v[i];
		} else if (max2 < v[i]) {
			max2 = v[i];
		}
		if (min1 > v[i]) {
			min2 = min1;
			min1 = v[i];
		} else if (min2 > v[i]) {
			min2 = v[i];
		}
	}
	if (min1 * min2 > max1 * max2) {
		std::cout << min1 << ' ' << min2;
	} else {
		std::cout << max2 << ' ' << max1;
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