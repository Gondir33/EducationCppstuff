#include <iostream>
#include <fstream>
#include <set>

int main() {
	std::ifstream	in("input.txt");
	std::string		s;
	std::set<int>	set;

	if (in.is_open())
		std::getline(in, s);
	in.close();
	int j;
	for (int i = 0; i < s.size(); ++i) {
		j = 0;
		while (i + j < s.size() && s[i + j] != ' ' && s[i + j] != '\n')
			++j;
		set.insert(std::stoi(s.substr(i, j)));
		i += j;
	}
	std::cout << set.size();
}