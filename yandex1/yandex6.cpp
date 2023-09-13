#include <iostream>
#include <vector>

int main() {
	int a1, b1, a2, b2;
	std::cin >> a1 >> b1 >> a2 >> b2;

	int max1 = std::max(a1, b1);
	int max2 = std::max(a2, b2);
	int min1 = std::min(a1, b1);
	int min2 = std::min(a2, b2);
	if (max1 == max2) {
		std::cout << max1 << ' ' << min1 + min2;
	} else if (min1 == min2) {
		std::cout << min1 << ' ' << max1 + max2;
	} else if (max1 == min2) {
		std::cout << min2 << ' ' << max2 + min1;
	} else if (max2 == min1) {
		std::cout << min1 << ' ' << max1 + min2;	
	} else if (max1 > max2) {
		if (min1 > max2) {
			std::cout << max1 + min2 << ' ' << min1;
		} else {
			std::cout << min1 + min2 << ' ' << max1;
		}
	} else {
		if (min2 > max1) {
			std::cout << max2 + min1 << ' ' << min2;
		} else {
			std::cout << min2 + min1 << ' ' << max2;
		}
	}
}