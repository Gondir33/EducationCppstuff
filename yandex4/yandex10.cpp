#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <fstream>

void	get_input(std::string&	s, 	std::unordered_set<std::string>&	keyWords, bool& startFromDigit) {
	bool	caseSensetivity;
	std::fstream	in("input.txt");
	size_t N;
	std::string	buff;

	if (in.is_open()) {
		size_t i = 0;
		getline(in, s);
		N = std::stoi(s, &i);
		++i;
		size_t len = 0;
		while (s[i + len] != ' ')
			++len;
		if (s.substr(i, len) == "yes")
			caseSensetivity = true;
		else if (s.substr(i, len) == "no")
			caseSensetivity = false;
		i += len;
		++i;
		len = 0;
		while (s[i + len] != ' ')
			++len;
		if (s.substr(i, len) == "yes")
			startFromDigit = true;
		else if (s.substr(i, len) == "no")
			startFromDigit = false;
		for (i = 0; i < N; ++i) {
			getline(in, s);
			keyWords.insert(s);
		}
		s = "";
		while (getline(in, buff)) {
			for (i = 0; i < buff.size(); ++i) {
				if  ((buff[i] < '0') || (buff[i] > '9' && buff[i] < 'A') || (buff[i] > 'Z' && buff[i] < '_') || (buff[i] > '_' && buff[i] < 'a') || (buff[i] > 'z')) {
					buff[i] = ' ';
				}
			}
			s += buff;
			s += ' ';
		}
	}
	in.close();
	if (caseSensetivity == false) {
		for (size_t i = 0; i < s.size(); ++i) {
			s[i] = std::tolower(s[i]);
		}
	}

}

int main() {
	std::unordered_set<std::string>	keyWords;
	bool							startFromDigit;
	std::string 	s;
	std::unordered_map<std::string, int>	ans;
	get_input(s, keyWords, startFromDigit);


	int 		max = 0;
	std::string	ansS, tmpS;
	size_t i = 0, len;
	while (i < s.size()) {
		if (startFromDigit == false) {
			while (s[i] >= '0' && s[i] <= '9')
				++i;
		}
		len = 0;
		while (s[i + len] != ' ')
			++len;
		tmpS = s.substr(i, len);
		++ans[tmpS];
		if (keyWords.count(tmpS) == 0) {
			if (max < ans[tmpS]) {
				max = ans[tmpS];
				ansS = tmpS;
			}
		}
		i += len;
		while (s[i] == ' ')
			++i;
	}
	std::cout << ansS;
}