#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>


int main(void)
{
	long long n, k, tmp;
	std::unordered_map<long long, long long>	hash_map;
	std::vector<long long>				v;
	std::cin >> n >> k;
	v.reserve(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> tmp;
		++hash_map[tmp];
	}
	for (auto& it : hash_map)
		v.push_back(it.first);
	std::sort(v.begin(), v.end());
	size_t l = 0, r = 0, ans = 0, duplicates = 0, range;
	while (l < v.size()) {
		while (r < v.size() && v[l] * k >= v[r]) {
			if (hash_map[v[r]] >= 2)
				++duplicates;
			++r;
		}
		range = r - l;
		if (hash_map[v[l]] >= 3)
			++ans;
		if (hash_map[v[l]] >= 2)
			ans += (range - 1) * 3;
		ans += (range - 1) * (range - 2) * 3;
		if (hash_map[v[l]] >= 2)
			--duplicates;
		ans += duplicates * 3;
		++l;
	}
	std::cout << ans;
	return 0;
}





















































/*
int main() {
	int n, k, tmp;
	size_t ans = 0, r_num = 0, l_num = 0;
	std::cin >> n >> k;
	std::map<int, int>	mp;
	for (int i = 0; i < n; ++i) {
		std::cin >> tmp;
		++mp[tmp];
	}
	auto	l = mp.begin();
	auto	r = mp.begin();
	
	while (r != mp.end() && (r->first - l->first <= k)) { // пиздец кринжа навалил просто стыдно
		++r;
		++r_num;
	}
	while (r != mp.end()) {
		if (l->second >= 3)
			++ans;
		if (l->second >= 2) {
			tmp = (r_num - l_num - 1) * 3;
			if (tmp > 0)
				ans += tmp;
		}
		if (l->second >= 1) {
			tmp = (r_num - l_num - 1) * (r_num - l_num - 2) * 6;
			if (tmp > 0)
				ans += tmp;
		}
		++l;
		++l_num;
		while (r != mp.end() && (r->first - l->first <= k)) {
			++r;
			++r_num;
		}
	}
	while (l != mp.end()) {
		if (l->second >= 3)
			++ans;
		if (l->second >= 2) {
			tmp = (r_num - l_num - 1) * 3;
			if (tmp > 0)
				ans += tmp;
		}
		if (l->second >= 1) {
			tmp = (r_num - l_num - 1) * (r_num - l_num - 2) * 6;
			if (tmp > 0)
				ans += tmp;
		}
		++l;
		++l_num;
	}
	std::cout << ans << '\n';
}*/