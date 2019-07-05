#include <iostream>
#include <vector>


struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { std::cout << __FUNCSIG__ << std::endl; }
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};

template <class T>
struct Mallocator {
	typedef T value_type;

	Mallocator() = default;

	template <class U> constexpr Mallocator(const Mallocator<U>&) noexcept {}
	T* allocate(std::size_t n) {
		if (n > std::size_t(-1) / sizeof(T)) throw std::bad_alloc();
		if (auto p = static_cast<T*>(std::malloc(n * sizeof(T)))) return p;
		throw std::bad_alloc();
	}
	void deallocate(T* p, std::size_t) noexcept { std::free(p); }

	void destroy(T* p)
	{
		std::cout << "MyAllocator Destroy" << std::endl;
	}

	// 아래 코드가 policy clone이름을 가진 기법이비다.
	template<typename U>
	struct rebind
	{
		typedef Mallocator<U> other;
	};
};

template <class T, class U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) { return true; }
template <class T, class U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) { return false; }

// List를 생각해 봅시다.
template<typename T, typename Ax = std::allocator<T>>
class List
{
	struct Node
	{
		T data;
		Node *next, *prev;
	};

	//Ax ax; // Mallocator<int> ax  --- int가 아닌 Node의 할당기가 있어야 한다.
	//Mallocator<Node> ax;
	//Mallocator<int>::rebind<Node> ax; // Mallocator<Node>

	typename Ax::template rebind<Node>::other ax; // Mallocator<Node>
public:
	void push_front(const T& a)
	{
		// memory할당 필요 - 184page code (해결책)rebind
	}
};


// int로 보냈는데 node를 만들 필요가 있을때는 어떻게 할  것인가?

int main()
{
	List<int, Mallocator<int>> s;
	s.push_front(10);
}

