#include <iostream>
#include <fstream>
#include <map>

int main() {
	std::ifstream	in("input.txt");
	std::string		s;
	std::map<std::string, int>	hash;


	if (in.is_open()) {
		while (std::getline(in, s)) {
			for (int i = 0; i < s.size(); ++i) {
				int j = 0;
				while (i + j < s.size() && s[i + j] != ' ' && s[i + j] != '\0') 
					++j;
				++hash[s.substr(i, j)];
				i += j;
			}
		}
	}
	in.close();
	std::string	ans;
	int max = 0;
	for (auto& it : hash) {
		if (max < it.second) {
			max = it.second;
			ans = it.first;
		}
	}
	std::cout << ans;
}