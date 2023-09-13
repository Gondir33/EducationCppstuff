#include <iostream>

int main( void ) {
	int					tmp;
	std::cin >> tmp;
	int max = tmp;
	int ans = 0;;
	while (tmp != 0) {
		if (max == tmp) {
			++ans;
		}
		if (max < tmp) {
			max = tmp;
			ans = 1;
		}
		std::cin >> tmp;
	}
	std::cout << ans;
}