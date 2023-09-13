#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

std::string low_str(const std::string& s1) {
	std::string	s(s1);
	for (int i = 0; i < s1.size(); ++i)
		s[i] = std::tolower(s1[i]);
	return	s;
} 

void	get_params(std::unordered_map<std::string, std::vector<std::string>>&	hash_map, std::string& s) {
	int N;
	std::ifstream	in("input.txt");

	if (in.is_open()) {
		getline(in, s);
		N = std::stoi(s);
		for (int i = 0; i < N; ++i) {
			getline(in, s);
			hash_map[low_str(s)].push_back(s);
		}
		getline(in, s);
	}
	in.close();


}

int main() {
	std::string	s;
	std::string	w;
	std::unordered_map<std::string, std::vector<std::string>>	hash_map;
	int j;
	int	ans = 0;
	bool	flag;
	get_params(hash_map, s);

	for (int i = 0; i < s.size(); ++i) {
		j = 0;
		while (i + j < s.size() && s[i + j] != ' ')
			++j;
		w = s.substr(i, j);
		i += j;
		
		int	count = 0;
		for (int k = 0; k < w.size(); ++k) {
			if (w[k] >= 'A' && w[k]  <= 'Z')
				++count;
		}
		if (count != 1) {
			++ans;
		} else if (hash_map.count(low_str(w)) == 1) {
			flag  = false;
			for (auto& it : hash_map[low_str(w)]) {
				if (it == w) {
					flag = true;
					break;
				}
			}
			if (flag == false)
				++ans;
		}
	}
	std::cout << ans;
}