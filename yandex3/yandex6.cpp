#include <iostream>
#include <unordered_set>

int main() {
	std::string								s1 ,s2;
	std::unordered_multiset<std::string>	set1;
	std::unordered_set<std::string>			set2;
	int ans = 0;
	std::cin >> s1 >> s2;

	for (int i = 0; i < s1.size() - 1; ++i)
		set1.insert(s1.substr(i, 2));
	for (int i = 0; i < s2.size() - 1; ++i)
		set2.insert(s2.substr(i, 2));
	for (auto& it : set2) {
		ans += set1.count(it);
	}
	std::cout << ans;
}