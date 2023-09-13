#include <iostream>

template <typename T>
struct allocator {
	void*	allocate(size_t n) {
		return ::operator new(n * sizeof (T));
	}

	void	deallocate(T* ptr, size_t ) {
		::operator delete(ptr);
	}

	template<typename... Args>
	void	construct(T* ptr, const Args&... args) {
		new (ptr) T(args...);
	}

	void	destroy(T* ptr) {
		ptr->~T();
	}
};

// allocator traits.
