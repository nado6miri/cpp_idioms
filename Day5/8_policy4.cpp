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
};

template <class T, class U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) { return true; }
template <class T, class U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) { return false; }

// 표준에 있는 allocator를 쓰지 말고 직접 만들어 보자.
int main()
{
	Mallocator<Point> ax;

	Point* p1 = ax.allocate(2); // 메모리 할당만
	/*
	ax.construct(&p1[0], 1, 2); // 생성자 호출
	ax.construct(&p1[1], 1, 2); // 생성자 호출

	ax.destroy(&p1[0]); // 소멸자 호출
	ax.destroy(&p1[1]); // 소멸자 호출
	*/

	// 아래 함수는 Point에 destroy가있는지 조사하고 없으면 static 호출,  Point에 destroy를 재 정의 하면 재정의한 함수 호출
	std::allocator_traits<Mallocator<Point>>::construct(ax, &p1[0], 1, 2);
	std::allocator_traits<Mallocator<Point>>::destroy(ax, &p1[0]);

	ax.deallocate(p1, 2); // 메모리 해제

}

