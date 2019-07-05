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

// ǥ�ؿ� �ִ� allocator�� ���� ���� ���� ����� ����.
int main()
{
	Mallocator<Point> ax;

	Point* p1 = ax.allocate(2); // �޸� �Ҵ縸
	/*
	ax.construct(&p1[0], 1, 2); // ������ ȣ��
	ax.construct(&p1[1], 1, 2); // ������ ȣ��

	ax.destroy(&p1[0]); // �Ҹ��� ȣ��
	ax.destroy(&p1[1]); // �Ҹ��� ȣ��
	*/

	// �Ʒ� �Լ��� Point�� destroy���ִ��� �����ϰ� ������ static ȣ��,  Point�� destroy�� �� ���� �ϸ� �������� �Լ� ȣ��
	std::allocator_traits<Mallocator<Point>>::construct(ax, &p1[0], 1, 2);
	std::allocator_traits<Mallocator<Point>>::destroy(ax, &p1[0]);

	ax.deallocate(p1, 2); // �޸� ����

}

