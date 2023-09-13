#include <iostream>
#include <unordered_map>

int match_map(std::unordered_map<char, int>& abc, std::unordered_map<char, int>& tmpabc) {
	int ans = 0;

	for (auto& it : abc) {
		if (tmpabc[it.first] == it.second)
			++ans;
	}
	return ans;
}

int down_match_dict(std::unordered_map<char, int>& abc, std::unordered_map<char, int>& tmpabc, char c) {
	int ans = 0;

	if (abc.count(c) == 1 && tmpabc[c] == abc[c])
		ans = -1;
	--tmpabc[c];
	if (abc.count(c) == 1 && tmpabc[c] == abc[c])
		ans = 1;
	return ans;
}

int up_match_dict(std::unordered_map<char, int>& abc, std::unordered_map<char, int>& tmpabc, char c) {
	int ans = 0;

	if (abc.count(c) == 1 && tmpabc[c] == abc[c])
		ans = -1;
	++tmpabc[c];
	if (abc.count(c) == 1 && tmpabc[c] == abc[c])
		ans = 1;
	return ans;
}

int main() {
	int	g, S, ans = 0, matchletters;
	std::string s;
	std::cin >> g >> S;
	std::unordered_map<char, int>	abc, tmpabc;
	std::cin >> s;
	for (int i = 0; i < g; ++i) {
		++abc[s[i]];
	}
	std::cin >> s;
	for (int i = 0; i < g; ++i) {
		++tmpabc[s[i]];
	}
	matchletters = match_map(abc, tmpabc);
	if (matchletters == abc.size())
		++ans;
	for (int i = g; i < S; ++i) {
		matchletters += down_match_dict(abc, tmpabc, s[i - g]);
		matchletters += up_match_dict(abc, tmpabc, s[i]);
		if (matchletters == abc.size())
			++ans;
	}
	std::cout << ans;
}
