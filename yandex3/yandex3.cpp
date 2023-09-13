#include <iostream>
#include <set>

int main() {
	int N, M;
	std::cin >> N >> M;
	std::set<int>	s1;
	std::set<int>	s2;
	int				tmp;
	for (int i = 0; i < N; ++i) {
		std::cin >> tmp;
		s1.insert(tmp);
	}
	for (int i = 0; i < M; ++i) {
		std::cin >> tmp;
		s2.insert(tmp);
	}
	tmp = 0;
	for (auto& it : s1)
		tmp += s2.count(it);
	std::cout << tmp << '\n';
	for (auto it = s1.begin(); it != s1.end(); ) {
		if (s2.count(*it) == 1) {
			std::cout << *it << ' ';
			s2.erase(*it);
			s1.erase(*(it++));
		} else {
			++it;
		}
	}
	std::cout << '\n' << s1.size() << '\n';
	for (auto& it : s1)
		std::cout << it << ' ';
	std::cout << '\n' << s2.size() << '\n';
	for (auto& it : s2)
		std::cout << it << ' ';
	std::cout << '\n';
}