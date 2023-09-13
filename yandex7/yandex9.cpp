#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

int main() {
	int K;
	std::ifstream	in("input.txt");
	std::string	s;

	if (in.is_open()) {
		std::getline(in, s);
		K = std::stoi(s);	
		std::getline(in, s);
	}
	in.close();
	std::unordered_set<char>	hash_set;
	int l = 0, r = 0, ans = 0;
	while (l < K) {
		if (hash_set.count(s[l]) == 1) {
			++ans;
		hash_set.insert(s[l]);
		++l;
	}

	while (l < s.size()) {
		if (hash_set.count(s[l]) == 1) {
			++ans;
		} else {
			if (hash_set.size() == K)
			r = l;
		}
	}



}