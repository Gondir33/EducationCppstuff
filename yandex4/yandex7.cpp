#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

void	deposit(std::unordered_map<std::string, int>& mp, std::vector<std::string>& s) {
	mp[s[1]] += std::stoi(s[2]);
}

void	withdraw(std::unordered_map<std::string, int>& mp, std::vector<std::string>& s) {
	mp[s[1]] -= std::stoi(s[2]);
}

void	balance(std::unordered_map<std::string, int>& mp, std::vector<std::string>& s) {
	if (mp.count(s[1]) == 1)
		std::cout << mp[s[1]] << '\n';
	else
		std::cout << "ERROR\n";
}

void	transfer(std::unordered_map<std::string, int>& mp, std::vector<std::string>& s) {
	int	val = std::stoi(s[3]);
	mp[s[1]] -= val;
	mp[s[2]] += val;
}

void	income(std::unordered_map<std::string, int>& mp, std::vector<std::string>& s) {
	int	val = std::stoi(s[1]);
	for (auto& it : mp) {
		if (it.second > 0)
			it.second += it.second * val / 100;
	}
}


void solution() {
	std::ifstream	in("input.txt");
	std::string		s;
	std::vector<std::string>	v;
	std::unordered_map<std::string, int>	mp;
	std::vector<std::string>		cmds {"DEPOSIT", "WITHDRAW", "BALANCE", "TRANSFER", "INCOME"};
	void	(*f[5])(std::unordered_map<std::string, int>& , std::vector<std::string>& ) = {deposit, withdraw, balance, transfer, income};

	if (in.is_open()) {
		
		while (getline(in, s)) {
			
			for (int i = 0; i < s.size(); ++i) {
				int j = 0;
				while (i + j < s.size()  && s[i + j] != ' ')
					++j;
				v.push_back(s.substr(i, j));
				i += j;
			}

			for (int i = 0; i < cmds.size(); ++i) {
				if (cmds[i] == v[0]) {
					f[i](mp, v);
					break ;
				}
			}
			v.clear();
		}
	}
	in.close();
}

int main() {
	solution();
}