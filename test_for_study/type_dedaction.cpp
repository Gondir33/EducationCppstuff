#include <iostream>

//type deduction
//decltype



template <typename T>
void	f() = delete;



int main() {
	int		x = 5;
	int&	y = x;
	auto&&	z = std::move(x);

	//f<decltype(z)>();	

	decltype(y)		k = x;
	decltype(z)&	l = k;
	// f<decltype(y)>();
	
	// f<decltype(z)>();
	// if expr is prvalue of type T, then decltype (expr) is T; example (decltype(x++) = int)// no calc to ++
	// if expr is lvalue of type T, then decltype (expr) is T&; example (decltype(++x)) = int&)
	// if expr is xvalue of type T, then decltype (expr) is T&&, example
}