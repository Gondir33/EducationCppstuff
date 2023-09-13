#include <iostream>
#include <memory>
#include <vector>


void	f(int x) {
	//RAII
	
	// std::shared_ptr<int>p(new int(5));// внутри есть счетчик для того чтобы удалить
	std::unique_ptr<int> p(new int(6));

	// auto pp = p; deleted copy constructor

	if (x==0)
		throw std::runtime_error(":(");\
	
	std::vector<std::unique_ptr<int>> v;

	for (int i = 0; i < 10; ++i) {
		v.emplace_back(new int(i));
	}

	// delete p;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}
