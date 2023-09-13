#include <iostream>
#include <vector>

int main( void )
{
	int 	N;
	std::cin >> N;
	std::vector<long>	vec(N);

	for (auto& it : vec) {
		std::cin >> it;
	}
	std::cout << vec[N / 2];
	return 0;
}
