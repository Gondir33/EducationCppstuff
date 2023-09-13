#include <iostream>
#include <fstream>

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
	size_t	prev_len = 0, ans = 0;
	for (size_t i = K; i < s.size(); ++i) {
		if (s[i] == s[i - K])
			++prev_len;
		else
			prev_len = 0;
		ans += prev_len;
	}
	std::cout << ans;
}