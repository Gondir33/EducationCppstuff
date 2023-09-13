#include <iostream>
#include <fstream>
#include <set>
int main() {
	std::ifstream			in("input.txt");
	std::string				s;
	std::set<std::string>	set;
	int						ans = 0, j;

	if (in.is_open()) {
		while (std::getline(in, s)) {
			for (int i = 0; i < s.size(); ++i) {
				j = 0;
				while (i + j < s.size() && s[i + j] != ' ') ++j;
				set.insert(s.substr(i, j));
				i += j;
			}
		}
	}
	in.close();
	std::cout << set.size();
}