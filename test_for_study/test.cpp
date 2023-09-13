#include <iostream>
#include <vector>
using namespace std;

vector<string> fizzBuzz(int n) {
	vector<string>  s(n);
	for (int i = 1; i <= n; ++i) {
		if (i % 3 == 0 && i % 5 == 0)
			s[i - 1] = "FizzBuzz";
		else if (i % 3 == 0)
			s[i - 1] = "Fizz";
		else if (i % 5 == 0)
			s[i - 1] = "Buzz";
		else
			s[i - 1] = std::to_string(i);
			
	}
	return s;
}
int main() {
	vector<string> v(fizzBuzz(4));

	for (const auto& i : v)
		std::cout << i << '\n';
}
