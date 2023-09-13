#include <iostream>
#include <memory>
#include <type_traits>

template <typename T> 
struct ControlBlock {
	size_t	shared_count;
	size_t	weak_count;
	T*		object = nullptr;


	template <typename... Args>
	ControlBlock(size_t count, Args&&... args) : count(count) {
		object = std::forward<T>(args...);
	}
};

template <typename T>
class shared_ptr {
private:
	T* 				ptr = nullptr;
	// size_t*			count = nullptr;
	ControlBlock<T>*	cptr;

	friend class weak_ptr;

	template <typename U, typename... Args>
	friend std::shared_ptr<T>	make_shared(Args&&... args);

	shared_ptr(ControlBlock* ptr) :ptr(&ptr->count), cptr(ptr) { }
public:

	explicit shared_ptr(T* ptr): ptr(ptr), cptr(1, ptr) {

	}

	~shared_ptr() {
		if (!cptr)
			--(cptr->shared_count);
		if (!cptr->shared_count) {
			delete ptr;
			if (!cptr->weak_count) {
				delete cptr;
			}
		}

		
	}
};

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <typename T, typename... Args>
std::shared_ptr<T>	make_shared(Args&&... args) {
	auto p = new ControlBlock(1, std::forward<Args>(args)...);
	return std::shared_ptr(p);
}

int main(int argc, char const *argv[])
{
	auto p = std::make_unique<int>(6);

	return 0;
}

template <typename T>
class weak_ptr {
private:
	ControlBlock<T>	cptr;

public:
	weak_ptr(const shared<T>& ptr) : cptr(ptr.cptr);

	bool expired() const {

	} // живой или нет

	shared_ptr<T> lock() const {

	}

	~weak_ptr() {
		if (!cptr) {

		}
	}
};
//enable_shared_from_this
//CRTP = Curiosly Recursive Template Pattern
template <typename T>
class enable_shared_from_this {
private:
	weak_ptr<T> ptr = nullptr;
protected:
	shared_ptr<T>	shared_from_this() const {
		//	if
		return ptr.lock();
	}
};

struct S : public enable_shared_from_this<S> {

	shared_ptr<S> getPointer() const {

		return shared_from_this();
	}
};

//if constexpr (std::is_base_of_v<enable_shared_from_this<T>, T>)