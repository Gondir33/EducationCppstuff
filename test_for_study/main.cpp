#include "Vector.hpp"

int main( void )
{
	Vector<int>	v(10, 10);

	for (int i = 0; i < 10; ++i) {
		std::cout << v[i] << '\n';
	}

	return 0;
}
