#include <iostream>

struct S {
private:

	int	a = 1;

public:


	auto	foo() {
		/*
		auto f = [this](int x) {
			std::cout << x + a <<'\n';
		};
		*///since c++ 14

		std::string	s = "zxxzDsadas";

		auto f = [s = std::move(s)](int x) {
			std::cout << x + s.size() <<'\n';
		};
		return f;
	}
};


int main(int argc, char const *argv[])
{
	auto	f = S().foo();//UB потому что ссылка в методе умирает...
	
}
