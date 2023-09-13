#include <iostream>
#include <fstream>
#include <set>

int main() {
	std::ifstream	in("input.txt");
	std::string		s1;
	std::string		s2;
	std::set<int>	set1;
	std::set<int>	set2;


	if (in.is_open()) {
		std::getline(in, s1);
		std::getline(in, s2);
	}
	in.close();
	int j;
	for (int i = 0; i < s1.size(); ++i) {
		j = 0;
		while (i + j < s1.size() && s1[i + j] != ' ' && s1[i + j] != '\n')
			++j;
		set1.insert(std::stoi(s1.substr(i, j)));
		i += j;
	}
	for (int i = 0; i < s2.size(); ++i) {
		j = 0;
		while (i + j < s2.size() && s2[i + j] != ' ' && s2[i + j] != '\n')
			++j;
		set2.insert(std::stoi(s2.substr(i, j)));
		i += j;
	}
	for (auto& it : set1) {
		if (set2.find(it) != set2.end())
			std::cout << it << ' ';
	}
}