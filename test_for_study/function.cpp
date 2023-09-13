#include <iostream>
#include <functional>
// std::function [&a = std::as_const(s)]

int main(int argc, char const *argv[])
{
	//			return bool; 2 int args
	std::function<bool(int , int)>	f;

	f = [](int x, int y) {
		std::cout << "ML!\n";
		return x < y;
	};

	f(1, 7/8);
	return 0;
}
