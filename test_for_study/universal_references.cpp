#include <iostream>
#include <utility>
#include <type_traits>

//universal refernces and reference collapsing
//f(const type& t) -> both but const
//f(type& t) -> only lavalue
//f(type&& t) -> only rvalue
//function for rvlalue and lvalue

template <typename T>
void	f(T&& x) {//T&&-> universal refernce

}


//std::move 
template <typename T>
std::remove_reference_t<T>&&	move(T&& x) noexcept { // T&& don't work always
	return	static_cast<std::remove_reference_t<T>&&>(x);
}

//std::forward
template <typename T>
T&&	forward(std::remove_reference_t<T>& x) noexcept {
	return static_cast<T&&> x;
}

struct S {

	S& operator=(const S& t) & {
		data = t.data;
	}

	std::string	f() & { // for lvlaue
		return data;
	}

	std::string	f() && { // for rvalue
		return std::move(data);
	}

private:
	std::string	data;
};

int main() {

	f(5);// T = int, decltype(x) = int&&

	int y = 5;
	f(y);//if (f(T&& t)) and y - lvalue, T = int&!!!; decltype(x) = int&
	//reference collapsing
	/*
	1) & + & = &
	2) & + && = &
	3) && + & = &
	4) && + && = &&
	*/
	S	s;
	std::move(s).f(); // lexic like that
}