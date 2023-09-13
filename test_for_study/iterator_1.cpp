#include <iterator>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <type_traits>
#include <algorithm>

template <typename Iterator, typename IteratorCategory>
void	my_advance_helper( Iterator& iter, int n, IteratorCategory ) {
		for (int i = 0; i < n; ++i, ++iter);
		std::cout << "uWu\n";
}

template <typename Iterator>
void	my_advance_helper( Iterator& iter, int n, std::random_access_iterator_tag) {
	iter += n;
	std::cout << "uWu\t uWu\n";
}

template <typename Iterator>
void	my_advance(Iterator& iter, int n) {
	
	my_advance_helper(iter, n, typename std::iterator_traits<Iterator>::iterator_category());
	
	/*	works well with constexpr too
	if constexpr ( std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category, std::random_access_iterator_tag> ) {
		my_advance_helper(iter, n, std::random_access_iterator_tag());
	} else {
		my_advance_helper(iter, n, 1);
	}
	*/
}

template <bool B, typename T, typename F>
struct conditional {
	using type = F;
};


template <typename T, typename F>
struct conditional<true, T, F> {
	using type = F;
};

template <bool B, typename T, typename F>
using conditional_t = typename conditional<B, T, F>::type;

template <typename iterator>
struct common_reverse_iterator {
	private:
		iterator iter;
	public:
		common_reverse_iterator(const iterator& iter) : iter(iter) { }

		common_reverse_iterator<iterator>&	operator++() {
			--iter;
			return *this;
		}
		iterator base() const {
			return iter;
		}
};


template <typename T>
class vector {
private:
	T 		*arr;
	size_t	sz;
	size_t	cap;
public:
	template <bool IsConst>
	struct common_iterator {
		private:
			conditional_t<IsConst, const T*, T*> ptr;
		public:
			common_iterator(T* ptr) : ptr(ptr) { }

			conditional_t<IsConst, const T&, T&> operator*() {
				return *ptr;
			}

			common_iterator<true>& operator++() {
				++ptr;
				return *this;
			}

			conditional_t<IsConst, const T*, T*> operator->() {
				return ptr;
			}
	};

	using iterator = common_iterator<true>;
	using const_iterator = common_iterator<false>;

	iterator& begin() const {
		return iterator(arr);
	}
	
	iterator& end() const {
		return iterator(arr + sz);
	}
	using reverse_iterator = common_reverse_iterator<iterator>;
	using const_reverse_iterator = common_reverse_iterator<const_iterator>;

	reverse_iterator	rbegin() const {
		return (arr + sz - 1);
	}

	reverse_iterator	rend() const {
		return (arr - 1);
	}
};


struct IsEven {
	bool	operator()(int x) const {
		return x % 2 == 0;
	}
};

template <typename Container>
class back_inserter_iterator {
private:
	Container& container;
public:
	back_inserter_iterator(Container& container) : container(container) {}

	back_inserter_iterator<Container&> operator++() {
		return *this;
	}

	back_inserter_iterator<Container&> operator*() {
		return *this;
	}

	back_inserter_iterator<Container&> operator=(const typename Container::value_type& value) {
		container.push_back(value);
		return *this;
	}
};

template <typename Container>
back_inserter_iterator<Container&> back_inserter(Container& container) {
	return back_inserter_iterator<Container&>(container);
}


int main ( void ) {
	std::list<int>	list = {1, 2, 3, 4, 5};
	std::list<int>::iterator iter1 = list.begin();
	my_advance(iter1, 3);
	// std::cout << *iter1 << std::endl;

	std::vector<int>	vector(100);
	std::copy_if(list.begin(), list.end(), std::back_inserter(vector), IsEven());
	//front_inserter
	//inserter (map, set) \\ binary tree


	for (auto it = vector.rbegin(); it != vector.rend(); ++it) {
		std::cout << *it << std::endl;
	}

}