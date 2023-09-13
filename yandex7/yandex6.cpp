#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

#define	BORN	1
#define	DIED	-1

int main() {
	int N, day1, month1, year1, day2, month2, year2;
	std::cin >> N;
	std::vector<std::vector<int>>	people;
	std::set<int>					ans;
	for (int i = 1; i <= N; ++i) {
		std::cin >> day1 >> month1 >> year1;
		std::cin >> day2 >> month2 >> year2;
		if (year2 - year1 == 18) {
			if (month2 - month1 == 0) {
				if (day2 - day1 > 0) {
					people.push_back({year1 + 18, month1, day1, BORN, i});
					people.push_back({year2, month2, day2, DIED, i});
				}
			} else if (month2 - month1 > 0) {
				people.push_back({year1 + 18, month1, day1, BORN, i});
				people.push_back({year2, month2, day2, DIED, i});
			}
		} else if (year2 - year1 > 18) {
			people.push_back({year1 + 18, month1, day1, BORN, i});
			people.push_back({year2 , month2, day2, DIED, i});
		}
	}
	std::sort(people.begin(), people.end());

	if (people.size() != 0) {
		for (size_t i = 0; i < people.size(); ++i) {
			if (people[i][3] == BORN) {
				ans.insert(people[i][4]);
			} else {
				if (ans.size() != 0) {
					for (auto& it : ans)
						std::cout << it << ' ';
					std::cout << '\n';
				}
				ans.clear();
			}
		}
	} else {
		std::cout << 0 << '\n';
	}
}