#include <iostream>
#include <math.h>

int main() {
	double a, b, c, d, e, f;
	std::cin >> a >> b >> c >> d >> e >> f;

	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
		std::cout << '5';
	} else if (a == 0 && b == 0 && e != 0) {
		std::cout << '0';
	} else if (c == 0 && d == 0 && f != 0) {
		std::cout << '0';
	} else if (a == 0 && b == 0 && e == 0) {
		if (c == 0) {
			std::cout << '4' << ' ' << f / d;
		} else if (d == 0) {
			std::cout << '3' << ' ' << f / c;
		} else {
			std::cout << '1' << ' ' << - c / d << ' ' << f / d;
		}
	} else if (c == 0 && d == 0 && f == 0) {
		if (a == 0) {
			std::cout << '4' << ' ' << e / b;
		} else if (b == 0) {
			std::cout << '3' << ' ' << e / a;
		} else {
			std::cout << '1' << ' ' << - a / b << ' ' << e / b;
		}
	} else if (a == 0 && c == 0) {
		if (e / b == f / d)
			std::cout << '4' << ' ' << e / b;
		else
			std::cout << '0';
	} else if (b == 0 && d == 0) {
		if (e / a == f / c)
			std::cout << '3' << ' ' << e / a;
		else
			std::cout << '0';
	} else if (e == 0 && f == 0) {
		if (a / c == b / d)
			std::cout << '1' << ' ' << - a / b << ' ' << '0';
		else
			std::cout << '2' << ' ' << '0' << ' ' << '0';
	} else if (a == 0) {
		std::cout << '2' << ' ' << (f - d * e / b) / c << ' ' << e / b; 
	} else if (b == 0) {
		std::cout << '2' << ' ' << e / a << ' ' << (f - c * e / a) / d; 
	} else if (c == 0) {
		std::cout << '2' << ' ' << (e - b * f / d) / a << ' ' << f / d;
	} else if (d == 0) {
		std::cout << '2' << ' ' << f / c << ' ' << (e - a * f / c) / b;
	} else if ((a / c == b / d) && (b / d == e / f) && (e / f == a / c)) {
		std::cout << '1' << ' ' << - c / d << ' ' << f / d;
	} else {
		double x = (f - d * e / b) / (c - d * a / b);
		double y = (e - a * x) / b;
		if (x == INFINITY || x == -INFINITY || x == NAN || x == -NAN || y == INFINITY || y == -INFINITY || y == NAN || y == -NAN)
			std::cout << '0';
		else
			std::cout << '2' << ' ' << x << ' ' << y;
	}
}