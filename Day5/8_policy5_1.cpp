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

	// �Ʒ� �ڵ尡 policy clone�̸��� ���� ����̺��.
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

// List�� ������ ���ô�.
template<typename T, typename Ax = std::allocator<T>>
class List
{
	struct Node
	{
		T data;
		Node *next, *prev;
	};

	//Ax ax; // Mallocator<int> ax  --- int�� �ƴ� Node�� �Ҵ�Ⱑ �־�� �Ѵ�.
	//Mallocator<Node> ax;
	//Mallocator<int>::rebind<Node> ax; // Mallocator<Node>

	typename Ax::template rebind<Node>::other ax; // Mallocator<Node>
public:
	void push_front(const T& a)
	{
		// memory�Ҵ� �ʿ� - 184page code (�ذ�å)rebind
	}
};


// int�� ���´µ� node�� ���� �ʿ䰡 �������� ��� ��  ���ΰ�?

int main()
{
	List<int, Mallocator<int>> s;
	s.push_front(10);
}

