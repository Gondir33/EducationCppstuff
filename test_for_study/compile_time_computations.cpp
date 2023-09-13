#include <iostream>
#include <type_traits>
#include <utility>
//compile time computatuions using templates

template <size_t N>
struct Fibonacci {
	static const size_t	value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0> {
	static const size_t value = 0;
};

template <>
struct Fibonacci<1> {
	static const size_t value = 1;
};

template <size_t N, size_t D>
struct IsPrimeHelper {
	static const bool value = N % D == 0
		? false
		: IsPrimeHelper<N, D - 1>::value;
};

template <size_t N>
struct IsPrimeHelper<N, 1> {
	static const bool	value = true;
};

template <size_t N>
struct IsPrime {
	static const bool	value = IsPrimeHelper<N, N - 1>::value;
};

template <size_t... Ints>
struct index_sequence {};

template <typename T, size_t N>
struct push_back;


template <size_t N, size_t... Ints>
struct push_back<index_sequence<Ints...>, N> {
	using type = index_sequence<Ints..., N>;
};

template <size_t N>
struct make_index_sequence_s {
	using type = typename push_back<typename make_index_sequence_s<N - 1>::type, N - 1>::type;
};

template <>
struct make_index_sequence_s<0> {
	using type = index_sequence<>;
};

template <size_t N>
using make_index_sequence = typename make_index_sequence_s<N>::type; 


//Basic reflection: detecting fields count

struct S {
	int		x;
	double	d;
};

int main() {

	// std::cout << Fibonacci<10>::value << '\n';
	// std::cout << IsPrime<17>::value << '\n';
	// std::cout << IsPrime<121321>::value << '\n';
	// static_assert(std::is_same_v< make_index_sequence<3>, index_sequence<0, 1, 2> >);



	return 0;
}
