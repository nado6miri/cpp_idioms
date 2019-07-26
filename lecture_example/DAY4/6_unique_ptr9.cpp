#include <iostream>
#include <memory>


template<typename T,
	typename U,
	bool b = std::is_empty<T>::value >
	struct PAIR;
template<typename T, typename U> struct PAIR<T, U, false>
{
	T v1;
	U v2;
	T& getValue1() { return v1; }
	U& getValue2() { return v2; }

	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: v1(std::forward<A>(a))
		, v2(std::forward<B>(b)) {}

	PAIR() = default;
};

template<typename T, typename U> struct PAIR<T, U, true> : public T
{
	U v2;
	T& getValue1() { return *this; }
	U& getValue2() { return v2; }

	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: T(std::forward<A>(a))
		, v2(std::forward<B>(b)) {}

	PAIR() = default;
};

template<typename T> struct default_delete
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete p;
	}
};
template<typename T> struct default_delete<T[]>
{
	inline void operator()(T* p)
	{
		std::cout << "default delete []" << std::endl;
		delete[] p;
	}
};




struct Freer
{
	inline void operator()(void* p)
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};

template<typename T, typename D = default_delete<T> >
class unique_ptr
{
	PAIR<D, T*> m;
public:
	//inline unique_ptr(T* p = 0, const D& del = D())	: m(del, p) {}


	template<typename Dx = D>
	inline unique_ptr(T* p = 0, Dx&& del = Dx())
		: m(std::forward<Dx>(del), p) {}




	inline ~unique_ptr()
	{
		m.getValue1()(m.getValue2());
	}

	inline T* operator->() { return m.getValue2(); }
	inline T& operator*() { return *(m.getValue2()); }

	// ����迭�� ����
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

	// move �迭�� ����.
	inline unique_ptr(unique_ptr&& p) noexcept
		: m(std::move(p.m))  // PAIR move ������
	{
		p.m.getValue2() = nullptr;
	}  


	inline unique_ptr& operator=(unique_ptr&& p) noexcept
	{
		m = std::move(p.m);
		p.m.getValue2() = nullptr;
		return *this;
	}
};



template<typename T, typename D>
class unique_ptr< T[], D >
{
	PAIR<D, T*> m; // PAIR<D, int*> m
public:
	inline unique_ptr(T* p = 0, const D& del = D())
		: m(del, p) {}

	inline ~unique_ptr()
	{
		m.getValue1()(m.getValue2());
	}
	// �迭 ���������� [] �� �����ϴ� ���� �����ϴ�.
	T& operator[](int idx)
	{
		// m.getValue2() : ������ ������ ������.
		return m.getValue2()[idx];
	}

	inline T* operator->() { return m.getValue2(); }
	//inline T& operator*() { return *(m.getValue2()); }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

int main()
{
	// �̹� �ҽ����� ���Ѱ�. 
	// 1. ������ ���� - forwarding reference ���
	// 2. unique_ptr �ȿ� move ������ �߰�.

	Freer f;
	unique_ptr<int, Freer>    p1(new int, std::move(f) );
	unique_ptr<int> p2(new int);

	//unique_ptr<int> p3 = p2; // error
	unique_ptr<int> p4 = std::move(p2); // �Ǿ� �Ѵ�.

//	unique_ptr<Dog> p5(new Dog); // ?
//	unique_ptr<Animal> p6 = std::move(p5);
}



