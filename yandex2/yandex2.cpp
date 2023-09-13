#include <iostream>
#include <vector>

int main() {
	std::vector<int>	v;
	int tmp;
	std::cin >> tmp;
	while (tmp != -2E9) {
		v.push_back(tmp);
		std::cin >> tmp;
	}
	bool CONSTANT = true;
	bool ASCENDING = true;
	bool WEAKLY_ASCENDING = true;
	bool DESCENDING = true;
	bool WEAKLY_DESCENDING = true;
	for (int i = 1; i < v.size(); ++i) {
		if (v[i - 1] != v[i])
			CONSTANT = false;
		if (v[i - 1] >= v[i])
			ASCENDING = false;
		if (v[i - 1] > v[i])
			WEAKLY_ASCENDING = false;
		if (v[i - 1] <= v[i])
			DESCENDING = false;
		if (v[i - 1] < v[i])
			WEAKLY_DESCENDING = false;
	}
	if (CONSTANT == true) {
		std::cout << "CONSTANT";
	} else if (ASCENDING == true) {
		std::cout << "ASCENDING";
	} else if (WEAKLY_ASCENDING == true) {
		std::cout << "WEAKLY ASCENDING";
	} else if (DESCENDING == true) {
		std::cout << "DESCENDING";
	} else if (WEAKLY_DESCENDING == true) {
		std::cout << "WEAKLY DESCENDING";
	} else {
		std::cout << "RANDOM";
	}
}