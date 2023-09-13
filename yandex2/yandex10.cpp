#include <iostream>

int main() {
	double	l = 30, r = 4000;
	double	prev, now;
	int n;
	std::cin >> n;
	std::cin >> prev;
	std::string	s;
	while (--n > 0) {
		std::cin >> now;
		std::cin >> s;
		if (std::abs(now - prev) <= 0.000001)
			continue ;
		if (s == "closer") {
			if (prev > now) {
				r = std::min((prev + now) / 2, r);
			} else {
				l = std::max((prev + now) / 2, l);
			}
		} else {
			if (prev > now) {
				l = std::max((prev + now) / 2, l);
			} else {
				r = std::min((prev + now) / 2, r);
			}
		}
		prev = now;
	}
	std::cout << l << ' ' << r;
}
//1761.95 1772