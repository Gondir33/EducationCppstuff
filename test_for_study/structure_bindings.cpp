#include <iostream>
#include <tuple>
int main() {
	std::pair<int, std::string> p{5, "abc"};
	// auto [a, b] = p; // a, b is a copy
	// std::cout << a << ' ' << b << '\n';
	std::tuple<int, double, std::string> t{1, 5, "asdfg"};
	// auto [a,b,c] = t;
	// std::cout << a << ' ' << b << ' ' << c << '\n';

	auto x = std::get<double>(t);
	std::cout << x << '\n';

}
/*
where it is usefull
std::map<int, std::string>;
for (auto& [key, value] : m) {
	do smth...
}
since c++17


*/

