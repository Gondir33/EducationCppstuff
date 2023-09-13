#include <iostream>
#include <fstream>
#include <unordered_map>

int main() {
	std::ifstream	in("input.txt");
	std::string		s;
	std::unordered_map<std::string, int>	hash;


	if (in.is_open()) {
		while (std::getline(in, s)) {
			for (int i = 0; i < s.size(); ++i) {
				int j = 0;
				while (i + j < s.size() && s[i + j] != ' ' && s[i + j] != '\0') 
					++j;
				std::cout << hash[s.substr(i, j)]++ << ' ';
				i += j;
			}
		}
	}
	in.close();
}