#include <iostream>

// Rvalue reference and rules of their initialization

int main() {

	int x = 0;

	// int& rx = 1; CE

	const int& crx = 2;


	// int&& rrx = x; CE
	int&& rrx = 0;
	
	int& rx = rrx;
}

//std::move() создает возможномть сдлеать rvalue ссылку из объекта, который был не обязательно только что был создан
//то есть работает как конст каст, то есть из конст в обычный, тут из lvalue->rvalue