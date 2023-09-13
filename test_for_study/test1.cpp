#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
int romanToInt(string s) {
	map<char, int>  m;
	int             res = 0;
	
	m[s.size() - 1]++;
	for (int i = s.size() - 2; i >= 0; --i) {
		if (s[i] != s[i + 1])
			--m[s[i]];
		else
			++m[s[i]];
	}
    map<char, int>    roman(std::pair<char, int>('I', 1));

	
}
*/
vector<vector<int>> threeSum(vector<int>& nums) {
	// unordered_map<int, int> map;
        vector<vector<int>>		res;
        int						l, r;
        bool                    similar;
	
		if (nums.size() < 3)
			return {};
		sort(nums.begin(), nums.end());
		if (nums[0] > 0)
			return {};
        for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0)
			l = i + 1;
			r =  nums.size() - 1;
			while (l < r) {
				if (nums[i] + nums[l] + nums[r] < 0)
					++l;
				else if (nums[i] + nums[l] + nums[r] > 0)
					--r;
				else {
					res.push_back({nums[i], nums[l], nums[r]});
					break ;
				}
			}
        }
        // for (int i = 0; i < static_cast<int>(res.size()) - 1; ++i) {
        //     similar = true;
        //     for (int j = 0; j < 3; ++j) {
        //         if (res[i][j] != res[i + 1][j])
        //             similar = false;
        //     }
		// 	if (similar == true)
		// 		res.erase(res.begin() + i);
        // }
        return res;
		/*
		for (int j = i + 1; j < nums.size(); ++j) {
			if (map.find(nums[j]) != map.end()) {
				res.push_back({nums[i], nums[j], - nums[j] - nums[i]});
			}
			map[nums[i] - nums[j]] = j;
		}
		map.clear();*/
}

int main( void ) {
	std::vector<int> v{-2,0,1,1,2};
	vector<vector<int>> res;
	res = threeSum(v);
	for (auto i : res) {
		for (auto j : i) {
			std::cout << j << ' ';
		}
		std::cout << '\n';
	}
}
