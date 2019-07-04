#include <iostream>
#include <memory>

class Empty {};

template<typename T
	, typename U
	, bool b = std::is_empty<T>::value>
	struct PAIR
{};

// �ᱹ ���� pair�� ������� �ʰ� �Ʒ� 2���� ���˴ϴ�. �� ��쿡�� ���� �ص� �˴ϴ�.
// �Ʒ� �ҽ��� boost lib �� "compress_pair" �Դϴ�.
// c++  ǥ���� unique_ptr ���鶧 �� ����� ���ȴ�.

template<typename T, typename U> struct PAIR<T, U, false> // �κ� Ư��ȭ
{
	T v1;
	U v2;
	T& getValue1() { return v1; };
	U& getValue2() { return v2; };

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : v1(std::forward(<A>(a)), v2(std::forward<B>(b)) {};

	PAIR() = default; // default �����ڸ� ������.  PAIR {} �� ���� �ǹ�
};

template<typename T, typename U> struct PAIR : public T
{
	U v2;
	T& getValue1() { return *this; };
	U& getValue2() { return v2; };

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : T(std::forward(<A>(a)), v2(std::forward<B>(b)) {};

	PAIR() = default; // default �����ڸ� ������.  PAIR {} �� ���� �ǹ�
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
		std::cout << "default [] delete" << std::endl;
		delete[]p;
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
	// main 2��° ��ó�� ����ϸ� T ==> int[] �̹Ƿ� �Ʒ� �ڵ尡 ������ �ּ�ó�� �˴ϴ�. �׷��� ���� �߻���. -> ���� unitque_ptr7���� ���� �ذ�����.
	PAIR<D, T*> m;  // PAIR(D, int[]*> ���·� ġȯ ---> ���� �߻�
public:
	inline unique_ptr(T* p = 0, const D& del = D())
		: m(del, p) {}
	inline ~unique_ptr()
	{
		m.getValue1()(m.getValue2());
	}

	inline T* operator->() { return (m.getValue2()); }
	inline T& operator*() { return *(m.getValue2()); }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};



template<typename T, typename D>
class unique_ptr<T[], D>
{
	// main 2��° ��ó�� ����ϸ� T ==> int[] �̹Ƿ� �Ʒ� �ڵ尡 ������ �ּ�ó�� �˴ϴ�. �׷��� ���� �߻���. -> ���� unitque_ptr7���� ���� �ذ�����.
	PAIR<D, T*> m;  // PAIR(D, int*> m , ���·� ġȯ ---> ok
public:
	inline unique_ptr(T* p = 0, const D& del = D())
		: m(del, p) {}
	inline ~unique_ptr()
	{
		m.getValue1()(m.getValue2());
	}

	// �迭 ���������� []�� �����ϴ� ���� �����ϴ�.
	T& operator[](int idx)
	{
		// m.getValue2() : ������ ������ ���ױ�
		return m.getValue2()[idx];
	}

	inline T* operator->() { return (m.getValue2()); }
	inline T& operator*() { return *(m.getValue2()); }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

/*
int main()
{
	unique_ptr<int>  p1(new int);
	unique_ptr<int[]>  p1(new int[10]);

}
*/

int main()
{
	std::unique_ptr<int> p1(new int);
	std::unique_ptr<int[]> p2(new int[10]);

	//p1[0] = 10; // error
	*p1 = 10; // ok
	p2[0] = 10; // ok
	// *p2 = 10; // error - �迭�� ��� ������ ���ϰ� �� ����
}