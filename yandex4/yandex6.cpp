#include <iostream>
#include <map>
#include <fstream>

std::map<std::string, std::map<std::string, size_t>> get_params() {
	std::map<std::string, std::map<std::string, size_t>>	mp;
	std::ifstream	in("input.txt");
	std::string		s, s1, s2;
	int j, i;

	if (in.is_open()) {
		while (getline(in, s)) {
			j = 0;
			i = 0;
			while (i + j < s.size() && s[i + j] != ' ') ++j;
			s1 = s.substr(i, j); i += j + 1; j = 0;
			while (i + j < s.size() && s[i + j] != ' ') ++j;
			s2 = s.substr(i, j); i += j + 1; j = 0;
			while (i + j < s.size() && s[i + j] != ' ') ++j;
			mp[s1][s2] += std::stoi(s.substr(i, j));	
		}
	}
	in.close();
	return mp;
}

int main() {
	std::map<std::string, std::map<std::string, size_t>>	mp = get_params();
	for (auto& it1 : mp) {
		std::cout << it1.first << ":\n";
		for (auto& it2 : it1.second) {
			std::cout << it2.first << ' ' << it2.second << '\n';
		}
	}
}