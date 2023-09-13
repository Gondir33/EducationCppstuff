#include <iostream>
#include <cmath>

int the_smallest_dist(int d, int x, int y) {
	double	a = std::sqrt(x * x + y * y);
	double	b = std::sqrt((d - x) * (d - x) +  y * y);
	double	c = std::sqrt((d - y) * (d - y) +  x * x);

	if (a <= b && a <= c)
		return 1;
	if (b <= c && b <= a)
		return 2;
	if (c <= a && c <= b)
		return 3;
	return 0;
}

int main( void ) {
	int	d, x, y;
	std::cin >> d >> x >> y;
	int sign1, sign2, sign3;
	// 1(0,0) 2(d,0) 3(0,d) 0(x,y)
	// (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)
	// (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)
	// (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0)
	sign1 = d * y;
	sign2 = (d - x) * d - d * y;
	sign3 = x * d;

	if (sign1 == 0 || sign2 == 0 || sign3 == 0) {
		std::cout << 0;
		return 0;
	}
	bool pos = (sign1 > 0 && sign2 > 0 && sign3 > 0);
	bool neg = (sign1 < 0 && sign2 < 0 && sign3 < 0);
	if (pos == 1 || neg == 1) {
		std::cout << 0;
		return 0;
	} else {
		std::cout << the_smallest_dist(d, x, y);
	}
	return 0;
}
