#include <iostream>
#include <vector>
#include <cmath>

#define SIZE 4

struct coord {
	double	x;
	double	y;
};

bool	is_parallel_and_equal(coord p1, coord p2, coord p3, coord p4) {
	double x1 = p2.x - p1.x;
	double y1 = p2.y - p1.y;
	double x2 = p4.x - p3.x;
	double y2 = p4.y - p3.y;

	double a = x1 * x2 + y1 * y2;
	double b = sqrt(x1 * x1 + y1 * y1);
	double c = sqrt(x2 * x2 + y2 * y2);


	double cos = a / b / c;
	if ((cos == 1.0 || cos == -1.0) && b == c)
		return true;
	else
		return false;
}

bool	solution(std::vector<coord>&& values) {

	if (is_parallel_and_equal(values[0], values[1], values[2], values[3]) == true)
		return true;
	if (is_parallel_and_equal(values[0], values[1], values[3], values[2]) == true)
		return true;
	if (is_parallel_and_equal(values[0], values[2], values[1], values[3]) == true)
		return true;
	if (is_parallel_and_equal(values[0], values[2], values[3], values[1]) == true)
		return true;
	if (is_parallel_and_equal(values[0], values[3], values[1], values[2]) == true)
		return true;
	if (is_parallel_and_equal(values[0], values[3], values[2], values[1]) == true)
		return true;
	return false;
}

int main( void )
{
	int N;
	std::cin >> N;
	std::vector<std::vector<coord>>	values(N);
	for (int i = 0; i < N; ++i) {
		values[i].resize(SIZE);
		for (auto& it1 : values[i]) {
			std::cin >> it1.x;
			std::cin >> it1.y;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (solution(std::move(values[i])) == true)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
	
}
