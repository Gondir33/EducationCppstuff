#include <iostream>
#include <vector>


int main () {
	std::vector<bool>	vec(10);
	for (auto it : vec) {
		std::cout << it << ' ';
	}	
}