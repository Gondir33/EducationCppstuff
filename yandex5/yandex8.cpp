#include <iostream>
#include <fstream>
#include <unordered_map>

int main() {
	int n, k, indexL = 0, indexR = 0;
	std::ifstream	in("input.txt");
	std::string	s, tmp;

	if (in.is_open()) {
		std::getline(in, s);
		int j = 0;
		while (j < s.size() && s[j] != ' ') 	++j;
		n = std::stoi(s.substr(0, j));
		++j;
		k = std::stoi(s.substr(j, s.size() - j));
		std::getline(in, s);
	}
	in.close();
	
	std::unordered_map<char, int>	dict;
	int l = 0;
	int r = 0;
	while (r < n) {
		++dict[s[r]];
		if (dict[s[r]] <= k) {
			if (r + 1 - l >= indexR - indexL) {
				indexL = l;
				indexR = r + 1;
			}
		} else {
			while (dict[s[r]] > k) {
				--dict[s[l]];
				++l;
			}
		}
		++r;
	}

	std::cout << indexR - indexL << ' ' << indexL + 1;
}
