#include <iostream>
#include <vector>
#include <type_traits>

//template meta programming, SFINAE and compile-time computations

// Idea of SFINAE and simple example

/*
template <typename T>
auto	f(const T& ) ->decltype(T().size()) {// SFINAE moment compile try to understand which version of function is better
	std::cout << 1 << '\n';
	return 1;
}
template <typename T>
auto	f(const T& ) { CE in this if T = int потому что в сигнатуре
	T	x;
	x.size()
	std::cout << 1 << '\n';
	return 1;
}
*/
/*
int	f(...) {
	std::cout << 2 << '\n';
	return 1;
}
*/

//std::enable_if, its usage and Implementation 

template <bool B, typename T = void>
struct enable_if { };

template <typename T>
struct enable_if<true, T> {
	using type = T;
};

template <bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;
/*
template <typename T, typename = enable_if_t<std::is_class_v<std::remove_reference_t<T>>>>
void	g(const T&) {
	std::cout << 1 << '\n';
}		

template <typename T, typename = enable_if_t<!std::is_class_v<std::remove_reference_t<T>>>>
void	g(T&&) {
	std::cout << 2 << '\n';
}
*/
//
//	decltype: expression of type T -> type T
//	declval: type T -> expression of type T
//
struct NDC {
	void	construct(int) {}
	void	construct(int, double) {}
	NDC() = delete;
};

template <typename T>
T&&	declval() noexcept;

template <typename T, typename... Args>
struct has_method_construct {
private:

	template <typename TT, typename... AArgs>
	static auto f(int) -> decltype(declval<TT>().construct(declval<AArgs>()...), int());

	template <typename...>
	static char f(...);

public:
	static const bool	value = std::is_same_v<decltype(f<T,Args...>(0)), int> ;
};

struct S {
	void	construct(int) {}
	void	construct(int, double) {}
};


template <typename T, typename... Args>
const bool has_method_construct_v = has_method_construct<T, Args...>::value;


// is_constructible is_copy_constructible etc
template <typename T>
struct is_constructible {
private:

	template <typename TT, typename... AArgs>
	static auto f(int) -> decltype(TT(declval<AArgs>()...), int());

	template <typename...>
	static char f(...);

public:
	static const bool	value = std::is_same_v<decltype(f<T>(0)), int> ;
};

template <typename T>
const bool is_constructible_v = is_constructible<T>::value;


//integral constant
template <typename T, T v>
struct integral_constant {
	static const T = v;
};

struct true_type: integral_constant<bool, true> {};

struct false_type: integral_constant<bool, false> {};

template <typename T>
struct is_nothrow_move_constructible {
private:

	// condition ? true : false - bad code style

	template <typename TT>
	static auto f(int) 
		-> integral_constant<bool, noexcept(TT(declval<TT>()))>
	
	template <typename...>
	static auto f(...) -> false_type;

public:
	static const bool	value = std::is_same_v(f<T>(0)::value), int> ;
};

template <typename T>
const bool is_nothrow_move_constructible_v = is_nothrow_move_constructible<T>::value;

template <typename T>
auto	move_if_noexcept(T& x)
	-> std::conditional_t<is_nothrow_move_constructible_v<T>, T&&, const T&> {

}

template <typename T>
const bool is_nothrow_move_constructible_v = is_nothrow_move_constructible<T>::value;

int main(int argc, char const *argv[])
{
	std::vector<int>	v{1, 2, 3, 4};
	// f(5);
	// g(v);
	// g(5);

	std::cout << has_method_construct_v<S, int> << '\n';
	std::cout << has_method_construct_v<S, int, int> << '\n';
	std::cout << has_method_construct_v<S, int, int, int> << '\n';
	std::cout << has_method_construct_v<NDC, int> << '\n';
	std::cout << has_method_construct_v<NDC, int, int> << '\n';
	std::cout << has_method_construct_v<NDC, int, int, int> << '\n';
	return 0;
}