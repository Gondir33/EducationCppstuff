#include <vector>
#include <iostream>
#include <utility> // std::move
// magic function std::move	and its applications

template <typename T>
void	swap(T& x,T& y) {
	T t = std::move(x);
	x = std::move(y);
	y = std::move(t);
}

int main() {

	std::string s = "abcdef";

	std::cout << s.size() << '\n';
	std::string ss = std::move(s);
	std::cout << ss.size() << ' ' << s.size() << '\n';

	std::vector<std::string> v;

	v.push_back(std::string("abc"));

	//std::move(s), можно обращаться к s, если нет присвооения	std::move из lvalue в rvalue
	//f(getObject()); getObject() итак rvalue 
}

