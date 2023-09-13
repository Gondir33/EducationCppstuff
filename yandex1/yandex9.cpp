#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int D, E;
	std::vector<int>	v(3);
	std::cin >> v[0] >> v[1] >> v[2] >> D >> E;

	int min_w = std::min(D, E);
	int max_w = std::max(D, E);

	std::sort(v.begin(), v.end());

	if (v[0] <= min_w && v[1] <= max_w) 
		std::cout << "YES";
	else
		std::cout <<"NO";
}