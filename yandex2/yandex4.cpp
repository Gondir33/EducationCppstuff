#include <iostream>
#include <vector>
#include <fstream>

int main() {
	std::vector<int>	v;
	std::string			s;
	std::ifstream	in("input.txt");
	if (in.is_open()) {
		getline(in, s);
	}
	in.close();
	int j;
	for (int i = 0; i < s.size(); ++i) {
		j = 0;
		while (s[i + j] != ' ' && s[j + i] != '\n' && j + i < s.size()) ++j;
		v.push_back(std::stoi(s.substr(i, j)));
		i = j + i;
	}
	int ans = 0;
	for (int i = 1; i < v.size() - 1; ++i) {
		if (v[i - 1] < v[i] && v[i] > v[i + 1]) 
			++ans;
	}
	std::cout << ans;
}