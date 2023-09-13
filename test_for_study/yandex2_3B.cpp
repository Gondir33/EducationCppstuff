#include <iostream>

int main(void) {
	std::string s;
	std::cin >> s;

	int r = s.size() - 1;
	int l = 0;
	int ans = 0;
	while (l < r) {
		if (s[l] != s[r])
			++ans;
		++l;
		--r;
	}
	std::cout << ans;
}